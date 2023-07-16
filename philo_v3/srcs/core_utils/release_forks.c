/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:07:22 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 23:07:22 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

/**
 * @brief Releases the forks.
 *
 * @param philo The philosopher.
*/
void	release_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->manager->forks_mutex);
	if (philo->left_fork->owner == philo)
	{
		philo->left_fork->owner = NULL;
		pthread_mutex_unlock(philo->left_fork);
		philo->left_fork->is_available = TRUE;
	}
	if (philo->right_fork->owner == philo)
	{
		philo->right_fork->owner = NULL;
		pthread_mutex_unlock(philo->right_fork);
		philo->right_fork->is_available = TRUE;
	}
	pthread_mutex_unlock(&philo->manager->forks_mutex);
}
