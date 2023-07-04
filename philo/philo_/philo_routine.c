/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:04:02 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/06/30 10:04:02 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_state_thinking(t_philo *philo);
static void	philo_state_eating(t_philo *philo);
static void	philo_state_sleeping(t_philo *philo);
static void	philo_state_dead(t_philo *philo);

/**
 * @brief The philosopher routine, for each philosopher thread
 *
 * @param philo_ptr The philosopher to run the routine
 * @return void* NULL
*/
void	*philo_routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *) philo_ptr;
	while (philo->status != DEAD)
	{
		if (philo_starved(philo))
			philo_state_dead(philo);
		else if (philo->status == THINKING)
			philo_state_thinking(philo);
		else if (philo->status == EATING)
			philo_state_eating(philo);
		else if (philo->status == SLEEPING)
			philo_state_sleeping(philo);
		if (philo_changed_status(philo))
		{
			philo_print_status(philo);
			philo_set_status(philo, philo->status);
		}
		usleep(100);
	}
	return (NULL);
}

static void	philo_state_dead(t_philo *philo)
{
	philo_set_status(philo, DEAD);
	put_forks(philo);
}

/**
 * @brief Function to run when the philosopher is thinking
 *
 * @param philo The philosopher to run the function
 * @return void
*/
static void	philo_state_thinking(t_philo *philo)
{
	if (philo_can_eat(philo))
	{
		take_forks(philo);
		philo_set_status(philo, EATING);
		philo->last_fork_take = get_current_mstime();
	}
}

/**
 * @brief Function to run when the philosopher is eating
 *
 * @param philo The philosopher to run the function
 * @return void
*/
static void	philo_state_eating(t_philo *philo)
{
	int	elapsed;

	elapsed = get_current_mstime() - philo->last_fork_take;
	if (elapsed >= philo->time_to_eat)
	{
		put_forks(philo);
		philo->last_eat = get_current_mstime();
		philo->eat_count += 1;
		philo_set_status(philo, SLEEPING);
	}
}

/**
 * @brief Function to run when the philosopher is sleeping
 *
 * @param philo The philosopher to run the function
 * @return void
*/
static void	philo_state_sleeping(t_philo *philo)
{
	int	elapsed;

	elapsed = get_current_mstime() - philo->last_eat;
	if (elapsed >= philo->time_to_sleep)
		philo_set_status(philo, THINKING);
}
