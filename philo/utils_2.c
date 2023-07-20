/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 02:17:46 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/18 02:17:46 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_mstime	curr_time(void)
{
	static t_mstime	start_time;
	t_mstime		curr_time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	curr_time = (t_mstime) tv.tv_sec * 1000 + (t_mstime) tv.tv_usec / 1000;
	if (start_time == 0)
		start_time = curr_time;
	curr_time = curr_time - start_time;
	return (curr_time);
}

void	philo_min_meals_checker(t_philo *philo)
{
	int	min_meals;

	min_meals = philo->args->min_meals;
	if ((min_meals != -1) && (philo->meals == min_meals))
	{
		pthread_mutex_lock(&philo->args->sync_mutex);
		philo->args->completed_meals_count += 1;
		if (philo->args->completed_meals_count == philo->args->philos_count)
			philo->args->can_run = STOPPED;
		pthread_mutex_unlock(&philo->args->sync_mutex);
	}
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
