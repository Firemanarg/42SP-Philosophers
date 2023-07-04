/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:13:58 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/06/28 16:13:58 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Returns the current time in milliseconds.
 *
 * @return t_mstime The current time in milliseconds.
 */
t_mstime	get_current_mstime(void)
{
	struct timeval	time;
	t_mstime		mstime;

	gettimeofday(&time, NULL);
	mstime = (t_mstime)time.tv_sec * 1000;
	mstime += (t_mstime)time.tv_usec / 1000;
	return (mstime);
}

/**
 * @brief Converts milliseconds to microseconds.
 *
 * @param mstime Time in milliseconds.
 * @return t_utime Time in microseconds.
 */
t_utime	mstime_to_utime(t_mstime mstime)
{
	return ((t_utime)mstime * 1000);
}
