/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:02:04 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 22:02:04 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static void	print_new_state(t_philo *philo);

/**
 * @brief Sets the philosopher state.
 *
 * @param philo The philosopher.
 * @param state The state to be set.
 *
 * @return 1 if the state was changed, 0 otherwise.
*/
int	set_philo_state(t_philo *philo, t_philo_state state)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&philo->state_mutex);
	if (philo->state != state)
	{
		philo->state = state;
		ret = 1;
		if (state == SLEEPING)
			philo->last_sleep_time = get_mstime();
		print_new_state(philo);
	}
	pthread_mutex_unlock(&philo->state_mutex);
	return (ret);
}

/**
 * @brief Prints the philosopher state.
 *
 * @param philo The philosopher.
*/
static void	print_new_state(t_philo *philo)
{
	char	*state;

	state = NULL;
	if (philo->state == EATING)
		state = "is eating";
	else if (philo->state == SLEEPING)
		state = "is sleeping";
	else if (philo->state == THINKING)
		state = "is thinking";
	else if (philo->state == DEAD)
		state = "died";
	if (state)
		print_message(philo, state);
}
