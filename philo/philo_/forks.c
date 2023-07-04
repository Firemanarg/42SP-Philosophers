/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:54:18 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/06/30 10:54:18 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Takes the forks from the table.
 *
 * @param philo The philosopher that will take the forks.
 * @return void
*/
void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork->mutex));
	philo_print_message(philo, "has taken a fork");
	philo->left_fork->status = UNAVAILABLE;
	pthread_mutex_lock(&(philo->right_fork->mutex));
	philo_print_message(philo, "has taken a fork");
	philo->right_fork->status = UNAVAILABLE;
	philo->last_fork_take = get_current_mstime();
}

/**
 * @brief Puts the forks back on the table.
 *
 * @param philo The philosopher that will put the forks back.
 * @return void
*/
void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->left_fork->mutex));
	pthread_mutex_unlock(&(philo->right_fork->mutex));
	philo->left_fork->status = AVAILABLE;
	philo->right_fork->status = AVAILABLE;
}
