/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_terminate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:57:20 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/06/30 13:57:20 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manager.h"

void	terminate_manager(t_manager *manager)
{
	int	i;

	i = 0;
	while (i < manager->philo_count)
	{
		pthread_join(manager->philos[i].thread, NULL);
		i += 1;
	}
	i = 0;
	while (i < manager->fork_count)
	{
		pthread_mutex_destroy(&((manager->forks + i)->mutex));
		i += 1;
	}
	pthread_mutex_destroy(&(manager->mutex));
	free(manager->philos);
	free(manager->forks);
}
