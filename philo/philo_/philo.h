/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:17:34 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/06/28 14:17:34 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include "utils.h"

/**
 * @brief Enum containing all possible status of a fork
 */
typedef enum		e_fstatus
{
	UNAVAILABLE = 0,
	AVAILABLE
}	t_fstatus;

/**
 * @brief Struct to represent a fork
 *
 * @param index Index of the fork at the table
 * @param status Status of the fork
 */
typedef struct		s_fork
{
	int				index;
	int				owner_index;
	t_fstatus		status;
	pthread_mutex_t	mutex;
}	t_fork;

/**
 * @brief Enum containing all possible actions of a philosopher.
 * Each philo can execute only a single action at time.
 */
typedef enum		e_pstatus
{
	NONE = -1,
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}	t_pstatus;

/**
 * @brief Struct to represent a philosopher
 *
 * @param thread The thread of the philosopher
 * @param index Index of the philosopher at the table
 * @param mutex Pointer to the mutex
 * @param eat_count How many times philosopher ate
 * @param status Current status of the philosopher
 * @param prev_status Previous status of the philosopher
 * @param left_fork Pointer to the left fork
 * @param right_fork Pointer to the right fork
 * @param time_to_die The time (in ms) a philosopher can live without eating
 * @param time_to_eat The time (in ms) a philosopher take to eat
 * @param time_to_sleep The time (in ms) a philosopher take to sleep
 * @param last_fork_take The time (in ms) the philosopher took the last fork
 * @param last_eat The time (in ms) the philosopher ate the last time
 * @param last_sleep The time (in ms) the philosopher slept the last time
 */
typedef struct		s_philo
{
	pthread_t		thread;
	int				index;
	pthread_mutex_t	*mutex;
	int				eat_count;
	t_pstatus		status;
	t_pstatus		prev_status;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_mstime		start_time;
	t_mstime		time_to_die;
	t_mstime		time_to_eat;
	t_mstime		time_to_sleep;
	t_mstime		last_fork_take;
	t_mstime		last_eat;
	t_mstime		last_sleep;
}	t_philo;

void				*philo_routine(void *philo_ptr);
void				take_forks(t_philo *philo);
void				put_forks(t_philo *philo);
int					philo_can_eat(t_philo *philo);
int					philo_starved(t_philo *philo);
void				philo_set_status(t_philo *philo, int status);
int					philo_changed_status(t_philo *philo);
void				philo_print_status(t_philo *philo);
void				philo_print_message(t_philo *philo, char *message);

#endif

