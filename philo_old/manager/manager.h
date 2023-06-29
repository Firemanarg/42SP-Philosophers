/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:34:56 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/04/20 15:34:56 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGER_H
# define MANAGER_H

# include "time.h"
# include "philo.h"

# define MIN_ARGC 5
# define MAX_ARGC 6

/* Struct containing all args passed by main function.
 * 'philos_count' is the number of philosophers and forks on the table.
 * 'time_to_die' is the time (in ms) a philosopher can live without eating.
 * 'time_to_eat' is the time (in ms) a philosopher take to eat.
 * 'time_to_sleep' is the time (in ms) a philosopher take to sleep.
 */
typedef struct s_table_args
{
	int			philos_count;
	t_mstime	time_to_die;
	t_mstime	time_to_eat;
	t_mstime	time_to_sleep;
	int			min_eating_turns;
}	t_table_args;

typedef struct s_table
{
	t_philo	**philos;
	t_fork	*forks;
	t_times	*max_durations;
	int		philos_count;
	int		has_min_eating_turns;
	int		min_eating_turns;
}	t_table;

typedef struct s_manager
{
	t_table	*table;
	int		can_proceed;
}	t_manager;

t_table			*new_table(t_table_args *args);
t_philo			**new_philo_array(int amount, t_times *max_durations);
t_table_args	*create_table_args(int argc, int argv);
void			init_manager(t_manager *manager);
void			start_simulation(t_manager *manager, int argc, char *argv[]);


#endif
