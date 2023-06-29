/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:33:33 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/04/20 15:33:33 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"

// t_utime	get_current_time(void)
// {
// 	struct timeval  tv;

// 	gettimeofday(&tv, NULL);
// double time_in_mill =
//          (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
// }

// Parei aqui. Estava fazendo o gerenciamento do tempo para ser compatível com
// métricas diferentes (milissegundos e microssegundos), já que os parâmetros
// de entrada são em milissegundos, mas o tempo medido é retornado em segundos e microssegundos, e também o comando usleep recebe um parâmetro em microssegundos.
t_time	get_current_time(void)
{
	t_time  time;

	gettimeofday(&time, NULL);
	return (time);
}

t_mstime	get_mstime(t_time time)
{
	t_mstime	mstime;
	time_t		seconds;
	suseconds_t	useconds;

	seconds = time.tv_sec;
	useconds = time.tv_usec;
	mstime = (seconds * 1000) + (useconds / 1000);
	return (mstime);
}

t_utime	get_utime(t_time time)
{
	t_mstime	mstime;
	time_t		seconds;
	suseconds_t	useconds;

	seconds = time.tv_sec;
	useconds = time.tv_usec;
	mstime = (seconds * 1000) + (useconds / 1000);
	return (mstime);
}

/* Return 1 if time1 > time2, or 0 if not.
 */
// int	is_time_greater_than(t_time *time1, t_time *time2)
// {
// 	int	greater_sec;

// 	greater_sec = time1->tv_sec > time2->tv_sec;
// 	if (time1->tv_sec > time2->tv_sec)
// 		return (1);
// 	else if (time1->tv_sec == time2->tv_sec)
// }

// t_mstime	utime_to_mstime(u_time time)
// {
// 	return (time / 1000.0);
// }

// t_utime	mstime_to_utime(ms_time time)
// {
// 	return (time * 1000);
// }
