/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:21:06 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 23:21:06 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	print_message(t_philo *philo, char const *message)
{
	pthread_mutex_lock(&philo->manager->print_mutex);
	printf("%lu %d %s\n", get_mstime() - philo->manager->start_time,
		philo->id, message);
	pthread_mutex_unlock(&manager->print_mutex);
}
