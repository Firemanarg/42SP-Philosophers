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

/**
 * @brief Time in milliseconds.
 **/
typedef long long	t_mstime;

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
	int			index;
	t_fstatus	status;
}	t_fork;

/**
 * @brief Enum containing all possible actions of a philosopher.
 * Each philo can execute only a single action at time.
 */
typedef enum		e_pstatus
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}	t_pstatus;

/**
 * @brief Struct to represent a philosopher
 *
 * @param id ID of the thread
 * @param index Index of the philosopher at the table
 * @param eat_count How many times philosopher ate
 * @param status Current status of the philosopher
 * @param left_philo Pointer to the left philosopher
 * @param right_philo Pointer to the right philosopher
 * @param left_fork Pointer to the left fork
 * @param right_fork Pointer to the right fork
 * @param last_eat Last time the philosopher ate
 * @param last_sleep Last time the philosopher slept
 * @param last_think Last time the philosopher thought
 */
typedef struct		s_philo
{
	pthread_t		id;
	int				index;
	int				eat_count;
	t_pstatus		status;
	struct	s_philo *left_philo;
	struct	s_philo *right_philo;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_mstime		last_eat;
	t_mstime		last_sleep;
	t_mstime		last_think;
}	t_philo;

#endif
