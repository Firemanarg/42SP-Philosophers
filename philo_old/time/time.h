/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:32:53 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/04/20 15:32:53 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include <unistd.h>
# include <sys/time.h>

// Struct containing time in seconds and microseconds.
typedef struct timeval	t_time;

// Time in milliseconds
typedef long long		t_mstime;

// Time in microseconds
typedef long long		t_utime;

/* Struct to represent times of/for each possible action.
 * Valid actions are thinking, eating and sleeping.
 */
typedef struct	s_times
{
	t_time	thinking;
	t_time	eating;
	t_time	sleeping;
}	t_times;

t_times		*new_times(t_time thinking, t_time eating, t_time sleeping);
t_time		new_time_by_mstime(t_mstime mstime);
t_time		get_current_time(void);
t_mstime	get_mstime(t_time time);
t_utime		get_utime(t_time time);
void		print_time(t_time *time);

#endif
