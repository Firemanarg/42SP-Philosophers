/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:25:36 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 20:25:36 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	*manager_routine(void *arg)
{
	t_manager	*manager;
	int			i;
	int			meals_completed;
	int			end_loop;

	manager = (t_manager *)arg;
	end_loop = FALSE;
	manager_routine_setup(manager);
	while (!end_loop)
	{
		pthread_mutex_lock(&manager->continue_check_mutex);
		manager->eat_done_count = 0;
		i = 0;
		while (i < manager->philos_count)
		{
			if (manager->philos[i].state == DEAD)
			{
				manager->someone_died = 1;
				break;
			}
			if (manager->philos[i].meals_count >= manager->meals_count)
				manager->eat_done_count += 1;
			i += 1;
		}
		meals_completed = (manager->eat_done_count == manager->philos_count);
		if (manager->someone_died || meals_completed)
		{
			manager->can_continue = 0;
			end_loop = TRUE;
		}
		pthread_mutex_unlock(&manager->continue_check_mutex);
		usleep(100);
	}
}

static void	manager_routine_setup(t_manager *manager)
{
	int			i;

	pthread_mutex_lock(&manager->sync_mutex);
	i = 0;
	while (i < manager->philos_count)
	{
		pthread_mutex_init(&manager->forks[i], NULL);
		init_philo(&manager->philos[i], i + 1, manager);
		i += 1;
	}
	pthread_mutex_unlock(&manager->sync_mutex);
}
