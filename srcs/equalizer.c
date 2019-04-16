/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equalizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:01:41 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/04/16 23:33:55 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 			stream_callback(
	const void *input, void *output,
	unsigned long frameCount,
	const PaStreamCallbackTimeInfo* timeInfo,
	PaStreamCallbackFlags statusFlags,
	void *userData )
{
	t_values	*values;

	(void)input;
	(void)timeInfo;
	(void)statusFlags;
	values = (t_values *)userData;
	read(values->wav, output,
		values->bytes_per_sample * values->num_chanels * frameCount);
	return paContinue;
}
void 			validation_wav(t_values *values)
{
	uint16_t	buf16;
	uint32_t	buf32;

	if ((read(values->wav, &buf32, 4) != 4 || buf32 != 0x46464952) ||
		(read(values->wav, &buf32, 4) != 4) ||
		(read(values->wav, &buf32, 4) != 4 || buf32 != 0x45564157) ||
		(read(values->wav, &buf32, 4) != 4 || buf32 != 0x20746d66) ||
		(read(values->wav, &buf32, 4) != 4 || buf32 != 16) ||
		(read(values->wav, &buf16, 2) != 2 || buf16 != 1) ||
		(read(values->wav, &values->num_chanels, 2) != 2 || !values->num_chanels) ||
		(read(values->wav, &values->sample_rate, 4) != 4) ||
		(lseek(values->wav, 6, SEEK_CUR) == -1) ||
		(read(values->wav, &buf16, 2) != 2 || !(values->bytes_per_sample = buf16 / 8)))
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

void				port_audio_open(t_values *values)
{
	PaStreamParameters out_param;
	PaError	ret;

	if (Pa_Initialize() != paNoError)
		ft_die("portaudio is huita");
	out_param.device = Pa_GetDefaultOutputDevice();
	if (out_param.device == paNoDevice)
		ft_die("portaidio is huita");
	out_param.channelCount = values->num_chanels;
	out_param.sampleFormat = values->sampleFormat;
	out_param.suggestedLatency = Pa_GetDeviceInfo( out_param.device )->defaultHighOutputLatency;
	ret = Pa_OpenStream(&values->stream, NULL, &out_param, values->sample_rate, 
		paFramesPerBufferUnspecified, 0, &stream_callback, values);
	// if (ret != paNoError)
	// {
	// 	if (values->stream)
	// 		Pa_CloseStream(values->stream);
	// 	ft_die("portaidio is huita");
	// }
	// if (Pa_StartStream(values->stream) != paNoError)
	// 	ft_die("portaudio is huita");
}

int				play(t_values *values)
{
	if ((values->wav = open(values->wav_file, O_RDONLY)) == -1)
		ft_die("can't open wav");
	validation_wav(values);
	port_audio_open(values);
	return(0);
}
