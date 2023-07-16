/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:09:49 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 22:09:49 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

/**
 * @brief Tries to take the forks.
 *
 * @param philo The philosopher.
*/
void	take_forks(t_philo *philo)
{
	t_manager	*manager;
	t_fork		*left_fork;
	t_fork		*right_fork;

	manager = philo->manager;
	left_fork = philo->left_fork;
	right_fork = philo->right_fork;
	pthread_mutex_lock(&manager->forks_mutex);
	if (left_fork->is_available && right_fork->is_available)
	{
		left_fork->is_available = FALSE;
		print_message(philo, "has taken a fork");
		right_fork->is_available = FALSE;
		print_message(philo, "has taken a fork");
		left_fork->owner = philo;
		right_fork->owner = philo;
		philo->last_fork_take = get_mstime();
		set_philo_state(philo, EATING);
	}
	pthread_mutex_unlock(&manager->forks_mutex);
}
