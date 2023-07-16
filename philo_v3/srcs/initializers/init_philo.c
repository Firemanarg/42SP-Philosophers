/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:15:03 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 21:15:03 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	init_philo(t_philo *philo, int id, t_manager *manager)
{
	int	index;
	int	philos_count;
	int	left_fork_index;
	int	right_fork_index;

	index = id - 1;
	philos_count = manager->philos_count;
	left_fork_index = (index + philos_count - 1) % philos_count;
	right_fork_index = (index + 1) % philos_count;
	philo->id = id;
	philo->manager = manager;
	philo->state = THINKING;
	philo->meals_count = 0;
	philo->last_meal = 0;
	philo->left_fork = manager->forks[left_fork_index];
	philo->right_fork = manager->forks[right_fork_index];
	pthread_mutex_init(&philo->state_mutex, NULL);
}
