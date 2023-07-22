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
		safeset_int(&philo->can_run, FALSE, &philo->mutex);
	}
	if (philo->id % 2 == 0)
		usleep(1000);
	while (safeget_int(&philo->can_run, &philo->mutex))
	{
		if (!philo_eat(philo))
			break ;
		if (!philo_sleep(philo))
			break ;
		if (!philo_think(philo))
			break ;
		usleep(50);
	}
	return (NULL);
}

void	*philo_king_routine(void *arg)
{
	t_philo_king	*king;
	t_philo			*philo;
	int				i;

	king = (t_philo_king *) arg;
	while (TRUE)
	{
		king->is_any_philo_dead = FALSE;
		king->completed_meals_count = 0;
		i = 0;
		while (i < king->args->philos_count)
		{
			philo = king->philos + i;
			if (!safeget_int(&philo->is_alive, &philo->mutex))
				king->is_any_philo_dead = TRUE;
			if (safeget_int(&philo->has_ate_enough, &philo->mutex))
				king->completed_meals_count += 1;
			i += 1;
		}
		if (king->is_any_philo_dead
			|| king->completed_meals_count == king->args->philos_count)
			return (stop_all_philos(king));
		usleep(50);
	}
	return (NULL);
}

int	philo_eat(t_philo *philo)
{
	int	min_meals;

	if (!safeget_int(&philo->can_run, &philo->mutex) || !is_alive(philo, TRUE))
		return (0);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	if (!safeget_int(&philo->can_run, &philo->mutex) || !is_alive(philo, TRUE))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (0);
	}
	print(philo, "has taken a fork");
	print(philo, "has taken a fork");
	print(philo, "is eating");
	if (action_timed_loop(philo, philo->args->time_to_eat))
	{
		print(philo, "died");
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		safeset_int(&philo->is_alive, FALSE, &philo->mutex);
		return (0);
	}
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->last_meal = curr_time(&philo->args->time_mutex);
	philo->meals += 1;
	min_meals = philo->args->min_meals;
	if ((min_meals != -1) && (philo->meals == min_meals))
		safeset_int(&philo->has_ate_enough, TRUE, &philo->mutex);
	return (1);
}

int	philo_sleep(t_philo *philo)
{
	if (!safeget_int(&philo->can_run, &philo->mutex) || !is_alive(philo, TRUE))
		return (0);
	print(philo, "is sleeping");
	if (action_timed_loop(philo, philo->args->time_to_sleep))
	{
		print(philo, "died");
		safeset_int(&philo->is_alive, FALSE, &philo->mutex);
		return (0);
	}
	return (1);
}

int	philo_think(t_philo *philo)
{
	if (!safeget_int(&philo->can_run, &philo->mutex) || !is_alive(philo, TRUE))
		return (0);
	print(philo, "is thinking");
	return (1);
}
