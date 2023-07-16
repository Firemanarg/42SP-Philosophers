/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_woke_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:01:05 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 23:01:05 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int	philo_woke_up(t_philo *philo)
{
	int			woke_up;
	t_mstime	passed_time;

	passed_time = get_mstime() - philo->last_sleep;
	woke_up = passed_time >= philo->manager->time_to_sleep;
	return (woke_up);
}
