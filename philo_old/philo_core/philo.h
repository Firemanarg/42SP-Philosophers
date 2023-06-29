/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:07:52 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/04/20 11:07:52 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "time.h"

/* Enum containing the status of a fork. If AVAILABLE, fork
 * is not being used and can be taken.
 */
typedef enum e_fstatus
{
	UNAVAILABLE = 0,
	AVAILABLE
}	t_fstatus;

/* Enum containing all possible actions of a philosopher.
 * Each philo can execute only a single action at time.
 */
typedef enum e_action
{
	THINKING,
	EATING,
	SLEEPING
}	t_action;

typedef struct s_fork
{
	int			owner_index;
	t_fstatus	is_available;
}	t_fork;

/* Struct to represent a philosopher
 * id -> ID of the thread;
 * index -> Index of the philosopher at the table;
 * last_time -> Last time (ms) philosopher did an action;
 * duration_of -> Max duration of an action. If philosopher
 *  last_time.thinking + curr_time > last_time.thinking
 *   duration_of.thinking, he dies.
 */
typedef struct s_philo
{
	pthread_t	id;
	int			index;
	t_times		*last_time;
	t_times		*duration_of;
	t_action	action;
	t_fork		*forks[2];
	int			forks_count;
}	t_philo;

t_philo		*new_philo(int index, t_times *max_durations);
void		*init_philo_thread(void *arg);
void		print_philo(t_philo *philo);
t_fork		new_fork(void);
void		release_fork(t_fork *_fork);
void		take_fork(t_fork *_fork);
void		philo_set_action(t_philo *philo, t_action action);
int			philo_is_eating(t_philo *philo);
int			philo_is_thinking(t_philo *philo);
int			philo_is_sleeping(t_philo *philo);
int			philo_can_eat(t_fork *prev_fork, t_fork *next_fork);

#endif
