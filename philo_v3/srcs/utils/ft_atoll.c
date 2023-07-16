/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:44:48 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 23:44:48 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Converts a string to a long long integer.
 *
 * @param str String to be converted.
 * @return int Returns the converted long long integer.
 */
int	ft_atoll(char *str)
{
	long long	i;
	long long	result;
	long long	sign;

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
