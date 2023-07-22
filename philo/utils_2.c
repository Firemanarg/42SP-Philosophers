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

t_mstime	curr_time(pthread_mutex_t *time_mutex)
{
	static t_mstime	start_time;
	t_mstime		curr_time;
	struct timeval	tv;

	(void) time_mutex;
	gettimeofday(&tv, NULL);
	curr_time = (t_mstime) tv.tv_sec * 1000 + (t_mstime) tv.tv_usec / 1000;
	// pthread_mutex_lock(time_mutex);
	if (start_time == 0)
		start_time = curr_time;
	curr_time = curr_time - start_time;
	// pthread_mutex_unlock(time_mutex);
	return (curr_time);
}

int	action_timed_loop(t_philo *philo, t_mstime max_time)
{
	t_mstime	start_time;

	if (!is_alive(philo, TRUE))
		return (1);
	start_time = curr_time(&philo->args->time_mutex);
	while (curr_time(&philo->args->time_mutex) - start_time < max_time)
	{
		if (!is_alive(philo, TRUE))
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

int	is_alive(t_philo *philo, int thread_safe)
{
	t_mstime	time_since_last_meal;
	t_mstime	time;

	if (thread_safe)
		pthread_mutex_lock(&philo->mutex);
	time = curr_time(&philo->args->time_mutex);
	time_since_last_meal = time - philo->last_meal;
	if (thread_safe)
		pthread_mutex_unlock(&philo->mutex);
	return (time_since_last_meal < philo->args->time_to_die);
}
