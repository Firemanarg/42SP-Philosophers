/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:49:26 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 21:49:26 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

/**
 * @brief The philosopher routine for the thread.
 *
 * @param arg The philosopher.
 *
 * @return void* Always NULL.
*/
void	*philo_routine(void *arg)
{
	t_philo			*philo;
	t_manager		*manager;
	t_philo_state	state;

	philo = (t_philo *) arg;
	manager = philo->manager;
	while (can_continue(manager))
	{
		state = get_philo_state(philo);
		if (state != DEAD && philo_starved(philo))
			set_philo_state(philo, DEAD);
		if (state == DEAD)
			continue ;
		else if (state == THINKING)
			philo_think(philo);
		else if (state == EATING)
			philo_eat(philo);
		else if (state == SLEEPING)
			philo_sleep(philo);
	}
	pthread_mutex_lock(&manager->sync_mutex);
	pthread_mutex_unlock(&manager->sync_mutex);
	return (NULL);
}

static void	philo_think(t_philo *philo)
{
	philo_take_forks(philo);
}

static void	philo_eat(t_philo *philo)
{
	if (philo_finished_meals(philo))
	{
		release_forks(philo);
		philo->last_meal = get_mstime();
		philo->meals_count += 1;
		set_philo_state(philo, SLEEPING);
	}
}

static void	philo_sleep(t_philo *philo)
{
	if (philo_woke_up(philo))
		set_philo_state(philo, THINKING);
}
