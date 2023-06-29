/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_inits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:33:59 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/04/20 15:33:59 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"

t_times	*new_times(t_time thinking, t_time eating, t_time sleeping)
{
	t_times	*times;

	times = malloc(sizeof(t_times));
	if (times == NULL)
		return (NULL);
	times->thinking = thinking;
	times->eating = eating;
	times->sleeping = sleeping;
	return (times);
}

t_time	new_time_by_mstime(t_mstime mstime)
{
	t_time	time;
	time_t	seconds;
	suseconds_t	useconds;

	seconds = mstime / 1000;
	useconds = (mstime % 1000) * 1000;
	time.tv_sec = seconds;
	time.tv_usec = useconds;
	return (time);
}
