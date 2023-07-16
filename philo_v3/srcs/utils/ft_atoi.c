/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:20:43 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 19:20:43 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Converts a string to an integer.
 *
 * @param str String to be converted.
 * @return int Returns the converted integer.
 */
int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i += 1;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i += 1;
	}
	return (result * sign);
}
