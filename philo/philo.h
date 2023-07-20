/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:40:20 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/17 17:40:20 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define RUNNING 1
# define STOPPED 0

/**
 * Steps of simulation:
 * 1. Validate arguments
 * 2. Initialize structures
 * 3. Initialize philosophers
 * 4. Check conditions inside loop
 * 5. Finish philosophers
 * 6. Free resources
 * 7. Exit
*/

/**
 * Organization of the project - Categories grouped by steps:
 * 1. Validation
 * 2. Initialization
 * 3. Simulation
 * 4. Cleaning
*/

typedef long long t_mstime;
typedef struct s_philo t_philo;
typedef struct s_args t_args;

typedef struct s_args
{
	int				philos_count;
	t_mstime		time_to_die;
	t_mstime		time_to_eat;
	t_mstime		time_to_sleep;
	int				min_meals;
	pthread_mutex_t	*out_mutex;
	pthread_mutex_t	*sync_mutex;
}	t_args;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				can_run;
	t_mstime		last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				meals;
	t_args			*args;
}	t_philo;

typedef struct s_philo_king
{
	pthread_t		thread;
	int				completed_meals_count;
	t_args			*args;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_philo_king;

// simulation.c
void		*philo_routine(void *arg);
int			action_timed_loop(t_philo *philo, t_mstime max_time);
void		philo_think(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);

// utils_1.c
void		init_philo(t_philo *philo, int id, t_args *args);
void		init_philo_king(t_philo_king *king, t_args *args);
void		print(t_philo *philo, char *msg);
long long	ft_atoll(const char *str);
int			safeget_int(int *var, pthread_mutex_t *mutex);
void		safeset_int(int *var, int value, pthread_mutex_t *mutex);
// int			can_continue_simulation(t_philo *philo);
// void		set_simulation_status(t_philo *philo, int status);

// utils_2.c
t_mstime	curr_time(void);
void		philo_min_meals_checker(t_philo *philo);
int			min(int a, int b);
int			max(int a, int b);

#endif
