/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 09:45:45 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/06 09:45:45 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manager.h"

void	*monitor_routine(void *manager_ptr)
{
	t_manager	*manager;
	int			i;
	int			all_philos_ate;

	manager = (t_manager *) manager_ptr;
	while (1)
	{
		pthread_mutex_lock(&(manager->mutex));
		all_philos_ate = 0;
		if (manager->eat_done_count != -1)
			all_philos_ate = (manager->eat_done_count == manager->philo_count);
		if (manager->death_flag || all_philos_ate)
		{
			i = 0;
			while (i < manager->philo_count)
			{
				manager->philos[i].is_running = 0;
				i += 1;
			}
			pthread_mutex_unlock(&(manager->mutex));
			break ;
		}
		pthread_mutex_unlock(&(manager->mutex));
		usleep(10);
	}
	terminate_manager(manager);
	return (NULL);
}
