/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:30:39 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/04 11:30:39 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Checks if the philosopher can eat.
 *
 * @param philo The philosopher to check.
 * @return int 1 if the philosopher can eat, 0 otherwise.
*/
int	philo_can_eat(t_philo *philo)
{
	if (philo->status != THINKING)
		return (0);
	if (philo->left_fork->status == AVAILABLE
		&& philo->right_fork->status == AVAILABLE)
		return (1);
	return (0);
}

/**
 * @brief Checks if the philosopher is starved.
 *
 * @param philo The philosopher to check.
 * @return int 1 if the philosopher is starved, 0 otherwise.
*/
int	philo_starved(t_philo *philo)
{
	if (get_current_mstime() > philo->last_eat + philo->time_to_die)
		return (1);
	return (0);
}

/**
 * @brief Sets the philosopher status.
 *
 * @param philo The philosopher to set the status.
 * @param status The status to set.
 * @return void
*/
void	philo_set_status(t_philo *philo, int status)
{
	philo->prev_status = philo->status;
	philo->status = status;
}

/**
 * @brief Checks if the philosopher status has changed.
 *
 * @param philo The philosopher to check.
 * @return int 1 if the status has changed, 0 otherwise.
*/
int	philo_changed_status(t_philo *philo)
{
	return (philo->prev_status != philo->status);
}

/**
 * @brief Prints the philosopher status.
 *
 * @param philo The philosopher to print the status.
 * @return void
*/
void	philo_print_status(t_philo *philo)
{
	if (philo->status == THINKING)
		philo_print_message(philo, "is thinking");
		// printf("%lld %d is thinking\n", time, philo->index);
	else if (philo->status == EATING)
		philo_print_message(philo, "is eating");
		// printf("%lld %d is eating\n", time, philo->index);
	else if (philo->status == SLEEPING)
		philo_print_message(philo, "is sleeping");
		// printf("%lld %d is sleeping\n", time, philo->index);
	else if (philo->status == DEAD)
		philo_print_message(philo, "died");
		// printf("%lld %d died\n", time, philo->index);
}

void	philo_print_message(t_philo *philo, char *message)
{
	t_mstime	time;

	pthread_mutex_lock(philo->mutex);
	time = get_current_mstime() - philo->start_time;
	printf("%12lld %d %s\n", time, philo->index, message);
	pthread_mutex_unlock(philo->mutex);
}
