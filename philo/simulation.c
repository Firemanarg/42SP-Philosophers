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
	if (philo->args->philos_count == 1)
	{
		print(philo, "has taken a fork");
		usleep(philo->args->time_to_die * 1000);
		print(philo, "died");
		safeset_int(&philo->is_alive, FALSE, &philo->mutex);
	}
	while (safeget_int(&philo->can_run, &philo->mutex))
	{
		if (safeget_int(&philo->is_alive, &philo->mutex))
		{
			philo_eat(philo);
			philo_sleep(philo);
			philo_think(philo);
		}
		usleep(100);
	}
	return (NULL);
}

void	*philo_king_routine(void *arg)
{
	t_philo_king	*king;
	t_philo			*philo;
	int				i;

	printf("philo_king_routine\n");
	king = (t_philo_king *) arg;
	while (TRUE)
	{
		king->is_any_philo_dead = FALSE;
		king->completed_meals_count = 0;
		i = 0;
		while (i < king->args->philos_count)
		{
			philo = king->philos + i;
			if (!philo->is_alive)
				king->is_any_philo_dead = TRUE;
			if (philo->has_ate_enough)
				king->completed_meals_count += 1;
		}
		if (king->is_any_philo_dead
			|| king->completed_meals_count == king->args->philos_count)
			return (stop_all_philos(king));
		usleep(100);
	}
}

void	philo_eat(t_philo *philo)
{
	int	min_meals;

	if (safeget_int(&philo->can_run, &philo->mutex))
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		print(philo, "has taken a fork");
		print(philo, "has taken a fork");
		print(philo, "is eating");
		if (action_timed_loop(philo, philo->args->time_to_eat))
		{
			print(philo, "died");
			safeset_int(&philo->is_alive, FALSE, &philo->mutex);
		}
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		philo->last_meal = curr_time();
		philo->meals += 1;
		min_meals = philo->args->min_meals;
		if ((min_meals != -1) && (philo->meals == min_meals))
			philo->has_ate_enough = TRUE;
	}
}

void	philo_sleep(t_philo *philo)
{
	if (safeget_int(&philo->can_run, &philo->mutex))
	{
		print(philo, "is sleeping");
		if (action_timed_loop(philo, philo->args->time_to_sleep))
		{
			print(philo, "died");
			safeset_int(&philo->is_alive, FALSE, &philo->mutex);
		}
	}
}

void	philo_think(t_philo *philo)
{
	if (safeget_int(&philo->can_run, &philo->mutex))
		print(philo, "is thinking");
}
