/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:04:15 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 22:04:15 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_philo_state	get_philo_state(t_philo *philo)
{
	t_philo_state	state;

	pthread_mutex_lock(&philo->state_mutex);
	state = philo->state;
	pthread_mutex_unlock(&philo->state_mutex);
	return (state);
}
