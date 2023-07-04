/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:49:40 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/06/28 15:49:40 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <sys/time.h>

/**
 * @brief Time in milliseconds.
 **/
typedef long long	t_mstime;

/**
 * @brief Time in microseconds.
 **/
typedef long long	t_utime;

int					ft_isdigit(char c);
int					ft_atoi(char *str);
long long			ft_atoll(char *str);
t_mstime			get_current_mstime(void);
t_utime				mstime_to_utime(t_mstime mstime);

#endif
