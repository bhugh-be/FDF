/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equalizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:02:26 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/20 20:11:56 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				get_mean(void *output, int s, t_values *values)
{
	int			i;
	int			m;

	i = 0;
	m = 0;
	while (i < s)
	{
		if (values->bytes_per_sample == 1)
			m += *(uint8_t *)output;
		if (values->bytes_per_sample == 2)
			m += *(uint16_t *)output / 256;
		if (values->bytes_per_sample == 4)
			m += *(uint32_t *)output / 65536;
		output = (uint8_t *)output + (values->bytes_per_sample *
			values->num_chanels);
		i++;
	}
	return (m / s);
}

void			vizualizer(t_values *values, void *output, unsigned long fc)
{
	int			s;
	int			i;
	int			j;
	double		res;

	s = fc / values->w;
	i = 0;
	while (i < values->w)
	{
		res = (get_mean(output, s, values) / 256.0 + 0.5) * 0.7;
		j = 0;
		while (j < values->h)
		{
			values->dots[j][i].hz = (values->dots[j][i].hz +
				values->dots[j][i].z) / 2 * res;
			j++;
		}
		i++;
	}
}

int				stream_callback(const void *input, void *output,
			unsigned long frame_count,
			const PaStreamCallbackTimeInfo *time_info,
			PaStreamCallbackFlags status_flags, void *user_data)
{
	t_values	*values;

	(void)input;
	(void)time_info;
	(void)status_flags;
	values = (t_values *)user_data;
	read(values->wav, output,
		values->bytes_per_sample * values->num_chanels * frame_count);
	if (values->sync == 1)
		return (paContinue);
	values->sync = 1;
	vizualizer(values, output, frame_count);
	return (paContinue);
}

void			validation_wav(t_values *values)
{
	uint16_t	buf16;
	uint32_t	buf32;

	if ((read(values->wav, &buf32, 4) != 4 || buf32 != 0x46464952) ||
		(read(values->wav, &buf32, 4) != 4) ||
		(read(values->wav, &buf32, 4) != 4 || buf32 != 0x45564157) ||
		(read(values->wav, &buf32, 4) != 4 || buf32 != 0x20746d66) ||
		(read(values->wav, &buf32, 4) != 4 || buf32 != 16) ||
		(read(values->wav, &buf16, 2) != 2 || buf16 != 1) ||
		(read(values->wav, &values->num_chanels, 2) != 2 ||
			!values->num_chanels) ||
		(read(values->wav, &values->sample_rate, 4) != 4) ||
		(lseek(values->wav, 6, SEEK_CUR) == -1) ||
		(read(values->wav, &buf16, 2) != 2 ||
			!(values->bytes_per_sample = buf16 / 8)))
		ft_die("wav is huita");
	if (values->bytes_per_sample == 1)
		values->sampleFormat = paInt8;
	else if (values->bytes_per_sample == 2)
		values->sampleFormat = paInt16;
	else if (values->bytes_per_sample == 4)
		values->sampleFormat = paInt32;
	else
		ft_die("wav is huita");
}

void			port_audio_open(t_values *values)
{
	PaStreamParameters	out_param;
	PaError				ret;

	if (Pa_Initialize() != paNoError)
		ft_die("portaudio is huita");
	out_param.device = Pa_GetDefaultOutputDevice();
	if (out_param.device == paNoDevice)
		ft_die("portaidio is huita");
	out_param.channelCount = values->num_chanels;
	out_param.sampleFormat = values->sampleFormat;
	out_param.suggestedLatency =
		Pa_GetDeviceInfo(out_param.device)->defaultHighOutputLatency;
	out_param.hostApiSpecificStreamInfo = NULL;
	ret = Pa_OpenStream(&values->stream, NULL, &out_param, values->sample_rate,
		paFramesPerBufferUnspecified, 0, stream_callback, values);
	if (ret != paNoError)
	{
		if (values->stream)
			Pa_CloseStream(values->stream);
		ft_die("portaidio is huita");
	}
	if (Pa_StartStream(values->stream) != paNoError)
		ft_die("portaudio is huita");
}
