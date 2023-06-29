/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:31:42 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/04/20 15:31:42 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_philo *philo)
{
	if (philo)
	{
		printf("Phylo: {");
		printf("\n\tIndex=%i,", philo->index);
		printf("\n\tID=%ld,", philo->id);
		printf("\n\tAction=");
		if (philo->action == THINKING)
			printf("THINKING,");
		else if (philo->action == EATING)
			printf("EATING,");
		else if (philo->action == SLEEPING)
			printf("SLEEPING,");
		printf("\n\tLast time: [T=%lld, E=%lld, S=%lld],", get_mstime(philo->last_time->thinking), get_mstime(philo->last_time->eating), get_mstime(philo->last_time->sleeping));
		printf("\n\tDuration of: [T=%lld, E=%lld, S=%lld],", get_mstime(philo->duration_of->thinking), get_mstime(philo->duration_of->eating), get_mstime(philo->duration_of->sleeping));
		printf("\n}\n");
	}
}
