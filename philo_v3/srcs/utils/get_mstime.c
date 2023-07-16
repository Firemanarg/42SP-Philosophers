/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mstime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:24:16 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 19:24:16 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Gets the current time in milliseconds.
 *
 * @return int Returns the current time in milliseconds.
 */
t_mstime	get_mstime(void)
{
	struct timeval	tv;
	t_mstime		result;

	gettimeofday(&tv, NULL);
	result = tv.tv_sec * 1000;
	result += tv.tv_usec / 1000;
	return (result);
}
