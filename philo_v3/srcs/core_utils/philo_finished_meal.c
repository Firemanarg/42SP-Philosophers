/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_finished_meal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:56:42 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 22:56:42 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

/**
 * @brief Checks if the philosopher finished his meal.
 *
 * @param philo The philosopher.
 *
 * @return 1 if the philosopher finished his meal, 0 otherwise.
*/
int	philo_finished_meal(t_philo *philo)
{
	int			finished;
	t_mstime	passed_time;

	passed_time = get_mstime() - philo->last_meal;
	finished = passed_time >= philo->manager->time_to_eat;
	return (finished);
}
