/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:40:42 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/06/28 15:40:42 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGER_H
# define MANAGER_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "philo.h"

/**
 * @brief Time in microseconds.
 **/
typedef long long		t_utime;

/**
 * @brief Struct to hold the manager data, used during execution.
 *
 * @param philo_count The number of philosophers on the table.
 * @param fork_count The number of forks on the table.
 * @param philos The array of philosophers.
 * @param forks The array of forks.
 * @param time_to_die The time (in ms) a philosopher can live without eating.
 * @param time_to_eat The time (in ms) a philosopher take to eat.
 * @param time_to_sleep The time (in ms) a philosopher take to sleep.
 * @param eat_min_count The minimum number of times a philosopher must eat.
 **/
typedef struct s_manager
{
	int			philo_count;
	int			fork_count;
	t_philo		*philos;
	t_fork		*forks;
	t_mstime	time_to_die;
	t_mstime	time_to_eat;
	t_mstime	time_to_sleep;
	int			eat_min_count;
}	t_manager;

t_mstime	get_current_mstime(void);
t_utime		mstime_to_utime(t_mstime mstime);

#endif
