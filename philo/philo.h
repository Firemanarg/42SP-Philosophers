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

# define TRUE 1
# define FALSE 0

/**
 * @brief Type used to store time in milliseconds.
*/
typedef long long	t_mstime;

/**
 * @brief Structure used to store the arguments.
 *
 * @param philos_count Number of philosophers.
 * @param time_to_die Time in milliseconds until a philosopher dies.
 * @param time_to_eat Time in milliseconds that a philosopher takes to eat.
 * @param time_to_sleep Time in milliseconds that a philosopher takes to sleep.
 * @param min_meals Minimum number of meals that each philosopher must eat.
 * @param out_mutex Mutex used to print messages.
*/
typedef struct s_args
{
	int				philos_count;
	t_mstime		time_to_die;
	t_mstime		time_to_eat;
	t_mstime		time_to_sleep;
	int				min_meals;
	pthread_mutex_t	out_mutex;
}	t_args;

/**
 * @brief Structure used to store the philosopher.
 *
 * @param id ID of the philosopher.
 * @param thread Thread of the philosopher.
 * @param mutex Mutex used to lock the philosopher.
 * @param is_alive Flag that indicates if the philosopher is alive.
 * @param has_ate_enough Flag that indicates if the philosopher has
 * eaten enough.
 * @param can_run Flag that indicates if the philosopher can run.
 * @param last_meal Time in milliseconds of the last meal.
 * @param left_fork Pointer to the left fork.
 * @param right_fork Pointer to the right fork.
 * @param meals Number of meals that the philosopher has eaten.
 * @param args Pointer to the arguments.
*/
typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	mutex;
	int				is_alive;
	int				has_ate_enough;
	int				can_run;
	t_mstime		last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				meals;
	t_args			*args;
}	t_philo;

/**
 * @brief Structure used to store the Philo King.
 *
 * @param thread Thread of the Philo King.
 * @param completed_meals_count Number of meals that all philosophers have
 * eaten.
 * @param is_any_philo_dead Flag that indicates if any philosopher is dead.
 * @param args Pointer to the arguments.
 * @param philos Pointer to the philosophers.
 * @param forks Pointer to the forks.
*/
typedef struct s_philo_king
{
	pthread_t		thread;
	int				completed_meals_count;
	int				is_any_philo_dead;
	t_args			*args;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_philo_king;

// simulation.c
void				*philo_routine(void *arg);
void				*philo_king_routine(void *arg);
int					philo_think(t_philo *philo);
int					philo_eat(t_philo *philo);
int					philo_sleep(t_philo *philo);

// utils_1.c
void				init_philo(t_philo *philo, int id, t_philo_king *king);
void				init_philo_king(t_philo_king *king, t_args *args);
void				*stop_all_philos(t_philo_king *king);
void				print(t_philo *philo, char *msg);
long long			ft_atoll(const char *str);

// utils_2.c
t_mstime			curr_time(void);
int					action_timed_loop(t_philo *philo, t_mstime max_time);
int					safeget_int(int *var, pthread_mutex_t *mutex);
void				safeset_int(int *var, int value, pthread_mutex_t *mutex);
int					is_alive(t_philo *philo, int thread_safe);

#endif
