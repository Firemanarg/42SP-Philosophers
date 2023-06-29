/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:31:09 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/04/20 15:31:09 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*new_philo(int index, t_times *max_durations)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	*philo = (t_philo){0, .index = index};
	philo->duration_of = max_durations;
	philo->action = THINKING;
	return (philo);
}

void	*init_philo_thread(void *philo_ptr)
{
	t_philo	*philo;
	t_time	curr_time;

	philo = (t_philo *) philo_ptr;
	curr_time = get_current_time();
	philo->last_time = new_times(curr_time, curr_time, curr_time);

	print_philo(philo);
	printf("\n");
}
