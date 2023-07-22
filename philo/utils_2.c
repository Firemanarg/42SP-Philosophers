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

/**
 * @brief Returns the current time in milliseconds.
 *
 * @return t_mstime Current time in milliseconds.
*/
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

/**
 * @brief Returns the current time in milliseconds.
 *
 * @param philo Pointer to the philosopher.
 * @param max_time Maximum time in milliseconds.
 *
 * @return int 1 if the philosopher is alive, 0 otherwise.
*/
int	action_timed_loop(t_philo *philo, t_mstime max_time)
{
	t_mstime	start_time;

	if (!is_alive(philo, TRUE))
		return (1);
	start_time = curr_time();
	while (curr_time() - start_time < max_time)
	{
		if (!is_alive(philo, TRUE))
			return (1);
		if (!safeget_int(&philo->can_run, &philo->mutex))
			return (0);
		usleep(1000);
	}
	return (0);
}

/**
 * @brief Safely gets the value of an integer (thread-safe).
 *
 * @param var Pointer to the variable.
 * @param mutex Mutex used to lock the variable.
 *
 * @return int Value of the variable.
*/
int	safeget_int(int *var, pthread_mutex_t *mutex)
{
	int	result;

	pthread_mutex_lock(mutex);
	result = *var;
	pthread_mutex_unlock(mutex);
	return (result);
}

/**
 * @brief Safely sets the value of an integer (thread-safe).
 *
 * @param var Pointer to the variable.
 * @param value Value to be set.
 * @param mutex Mutex used to lock the variable.
*/
void	safeset_int(int *var, int value, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*var = value;
	pthread_mutex_unlock(mutex);
}

/**
 * @brief Checks if the philosopher is alive.
 *
 * @param philo Pointer to the philosopher.
 * @param thread_safe Flag that indicates if the function should lock the
 * philosopher mutex.
 *
 * @return int 1 if the philosopher is alive, 0 otherwise.
*/
int	is_alive(t_philo *philo, int thread_safe)
{
	t_mstime	time_since_last_meal;
	t_mstime	time;

	if (thread_safe)
		pthread_mutex_lock(&philo->mutex);
	time = curr_time();
	time_since_last_meal = time - philo->last_meal;
	if (thread_safe)
		pthread_mutex_unlock(&philo->mutex);
	return (time_since_last_meal < philo->args->time_to_die);
}
