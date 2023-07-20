/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:46:39 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/17 17:46:39 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		usleep(1500);
	if (philo->args->philos_count == 1)
	{
		print(philo, "has taken a fork");
		usleep(philo->args->time_to_die * 1000);
		print(philo, "died");
		set_simulation_status(philo, STOPPED);
	}
	while (can_continue_simulation(philo))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		philo_min_meals_checker(philo);
		usleep(100);
	}
	return (NULL);
}

int	action_timed_loop(t_philo *philo, t_mstime max_time)
{
	t_mstime	time_since_last_meal;
	t_mstime	start_time;

	start_time = curr_time();
	while (curr_time() - start_time < max_time)
	{
		time_since_last_meal = curr_time() - philo->last_meal;
		if (time_since_last_meal >= philo->args->time_to_die)
			return (1);
		if (!can_continue_simulation(philo))
			return (0);
		usleep(1000);
	}
	return (0);
}

void	philo_think(t_philo *philo)
{
	if (can_continue_simulation(philo))
		print(philo, "is thinking");
}

void	philo_eat(t_philo *philo)
{
	if (can_continue_simulation(philo))
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		print(philo, "has taken a fork");
		print(philo, "has taken a fork");
		print(philo, "is eating");
		if (action_timed_loop(philo, philo->args->time_to_eat))
		{
			print(philo, "died");
			set_simulation_status(philo, STOPPED);
		}
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		philo->last_meal = curr_time();
		philo->meals += 1;
	}
}

void	philo_sleep(t_philo *philo)
{
	if (can_continue_simulation(philo))
	{
		print(philo, "is sleeping");
		if (action_timed_loop(philo, philo->args->time_to_sleep))
		{
			print(philo, "died");
			set_simulation_status(philo, STOPPED);
		}
	}
}
