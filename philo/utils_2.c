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
		if (!safeget_int(&philo->can_run, &philo->mutex))
			return (0);
		usleep(1000);
	}
	return (0);
}

int	safeget_int(int *var, pthread_mutex_t *mutex)
{
	int	result;

	pthread_mutex_lock(mutex);
	result = *var;
	pthread_mutex_unlock(mutex);
	return (result);
}

void	safeset_int(int *var, int value, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*var = value;
	pthread_mutex_unlock(mutex);
}
