/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:30:49 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/04/20 15:30:49 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_set_action(t_philo *philo, t_action action)
{
	philo->action = action;
	printf("%lld %i is ", get_mstime(get_current_time()), philo->index + 1);
	if (action == THINKING)
		printf("thinking\n");
	else if (action == EATING)
		printf("eating\n");
	else if (action == SLEEPING)
		printf("sleeping\n");
}

int	philo_is_eating(t_philo *philo)
{
	return (philo->action == EATING);
}

int	philo_is_thinking(t_philo *philo)
{
	return (philo->action == THINKING);
}

int	philo_is_sleeping(t_philo *philo)
{
	return (philo->action == SLEEPING);
}

int	philo_can_eat(t_fork *prev_fork, t_fork *next_fork)
{
	return (prev_fork->is_available && next_fork->is_available);
}
