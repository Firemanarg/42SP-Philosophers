/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_starved.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:51:58 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 22:51:58 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

/**
 * @brief Checks if the philosopher is starved.
 *
 * @param philo The philosopher.
 *
 * @return 1 if the philosopher is starved, 0 otherwise.
*/
int	philo_starved(t_philo *philo)
{
	int			starved;
	t_mstime	passed_time;

	passed_time = get_mstime() - philo->last_meal;
	starved = passed_time > philo->manager->time_to_die;
	return (starved);
}
