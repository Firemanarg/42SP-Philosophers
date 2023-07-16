/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:47:20 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 09:47:20 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "utils.h"

/**
 * @brief Philosopher's state
 *
 * @param THINKING Philosopher is thinking
 * @param EATING Philosopher is eating
 * @param SLEEPING Philosopher is sleeping
 * @param DEAD Philosopher is dead
*/
typedef enum e_philo_state
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}	t_philo_state;

/**
 * @brief Philosopher struct
 *
 * @param id Philosopher's id
 * @param state Philosopher's state
 * @param previous_state Philosopher's previous state
 * @param meals_count Number of meals that the philosopher has eaten
 * @param last_meal Time in milliseconds that the philosopher has eaten
 * @param thread Thread that represents the philosopher
 * @param left_fork Mutex that represents the left fork
 * @param right_fork Mutex that represents the right fork
 * @param manager Pointer to the manager struct
*/
typedef struct s_philo
{
	int				id;
	t_philo_state	state;
	pthread_mutex_t	state_mutex;
	t_utime			initial_delay;
	int				meals_count;
	t_mstime		last_fork_take;
	t_mstime		last_meal;
	t_mstime		last_sleep;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_manager		*manager;
}	t_philo;

/**
 * @brief Fork struct
 *
 * @param mutex Mutex that represents the fork
 * @param is_available Flag to check if the fork is available
*/
typedef struct s_fork
{
	int				is_available;
	t_philo			owner;
}	t_fork;

/**
 * @brief Manager struct
 *
 * @param can_continue Flag to check if the simulation can continue
 * @param continue_check_mutex Mutex to check if the simulation can continue
 * @param print_mutex Mutex to print messages
 * @param forks Array of mutexes to represent the forks
 * @param philos Array of philosophers
 * @param philos_count Number of philosophers
 * @param time_to_die Time in milliseconds that a philosopher can stay
 * without eating
 * @param time_to_eat Time in milliseconds that a philosopher takes to eat
 * @param time_to_sleep Time in milliseconds that a philosopher takes to sleep
 * @param meals_count Number of meals that a philosopher must eat before
 * finishing the simulation
 * @param eat_done_count Number of meals that the philosophers have eaten
 * @param start_time Time in milliseconds that the simulation started
 * @param someone_died Flag to check if someone died
*/
typedef struct s_manager
{
	pthread_t		thread;
	int				can_continue;
	pthread_mutex_t	continue_check_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	sync_mutex;
	pthread_mutex_t	forks_mutex;
	t_fork			*forks;
	t_philo			*philos;
	int				philos_count;
	t_mstime		time_to_die;
	t_mstime		time_to_eat;
	t_mstime		time_to_sleep;
	int				meals_count;
	int				eat_done_count;
	t_mstime		start_time;
	int				someone_died;
}	t_manager;

/*
 * Inicializar o manager, incluindo os mutexes dos forks e as structs dos
 * filósofos.
 * Ao inicializar os filósofos, no momento de inicializar as threads,
 * aguardar o mutex de sincronização.
 *
 * A ideia é de que o manager cheque se algum filósofo morreu a cada 10ms.
 * Se algum filósofo morreu, o manager deve finalizar todas as threads e
 * retornar.
 *
 * Se um filósofo morrer, ele deve permanecer no loop de execução, mas não
 * deve executar nenhuma ação.
 *
 * A flag can_continue será compartilhada entre o manager e os filósofos.
 * Somente o manager poderá alterar o valor da flag.
 * O mutex continue_check_mutex será utilizado para que os filósofos possam
 * checar o valor da flag sem que o manager esteja alterando o valor.
 *
 * Usar o sync_mutex para sincronizar o início da execução dos filósofos,
 * e também para sincronizar o final da execução dos filósofos.
 * A primeira thread a bloquear o sync_mutex será a do manager, e só liberará
 * o mutex quando todas as threads dos filósofos estiverem bloqueadas.
 *
 * Usar o state_mutex para sincronizar o acesso ao estado do filósofo.
 * De preferência, criar uma função para automatizar esse acesso.
*/

// Initializers
int				init_manager(t_manager *manager, int argc, char **argv);
int				init_philo(t_philo *philo, int id, t_manager *manager);

// Routines
void			*manager_routine(void *arg);
void			*philo_routine(void *arg);

// Checkers
int				can_continue(t_manager *manager);

// Core utils
int				set_philo_state(t_philo *philo, t_philo_state state);
t_philo_state	get_philo_state(t_philo *philo);
void			take_forks(t_philo *philo);
void			release_forks(t_philo *philo);
int				philo_starved(t_philo *philo);
int				philo_finished_meal(t_philo *philo);
int				philo_woke_up(t_philo *philo);
void			print_message(t_philo *philo, char const *message);

#endif
