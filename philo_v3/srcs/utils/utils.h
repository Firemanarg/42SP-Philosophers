/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:35:26 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 18:35:26 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define TRUE 1
# define FALSE 0

# include <sys/time.h>

/**
 * @brief Time in milliseconds
*/
typedef long long	t_mstime;

/**
 * @brief Time in microseconds
*/
typedef long long	t_utime;

int	ft_isdigit(char c);
int	is_valid_number(char *str);
int	ft_atoi(char *str);
int	ft_atoll(char *str);
int	get_ms_time(void);

#endif
