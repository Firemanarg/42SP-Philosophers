/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:21:36 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/07 09:21:36 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manager.h"

/**
 * @brief Initializes a philosopher (except the thread)
 *
 * @param philo The philosopher to be initialized.
 * @param manager The manager.
 * @param index The philosopher index.
 * @return void
*/
void	init_philo(t_philo *philo, t_manager *manager, int index)
{
	int	right_fork_index;
	int	left_fork_index;

	philo->is_running = 1;
	philo->index = index + 1;
	philo->mutex = &(manager->mutex);
	philo->manager_eat_done_count = &(manager->eat_done_count);
	philo->manager_death_flag = &(manager->death_flag);
	philo->eat_count = 0;
	philo->eat_min_count = manager->eat_min_count;
	philo->manager_eat_done_count = &(manager->eat_done_count);
	philo->manager_death_flag = &(manager->death_flag);
	right_fork_index = (index + 1) % manager->fork_count;
	left_fork_index = (index + manager->fork_count - 1) % manager->fork_count;
	philo->left_fork = manager->forks + left_fork_index;
	philo->right_fork = manager->forks + right_fork_index;
	philo->is_holding_left_fork = 0;
	philo->is_holding_right_fork = 0;
	philo->start_time = manager->start_time;
	philo->time_to_die = manager->time_to_die;
	philo->time_to_eat = manager->time_to_eat;
	philo->time_to_sleep = manager->time_to_sleep;
	philo->last_fork_take = 0;
	philo->last_eat = get_current_mstime();
	philo->last_sleep = get_current_mstime();
	philo->status = NONE;
	philo->prev_status = NONE;
}
