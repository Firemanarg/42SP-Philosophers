/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:34:59 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 18:34:59 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Checks if a string is a valid number.
 *
 * @param str String to be checked.
 * @return int Returns 1 if the string is a valid number, 0 otherwise.
 */
int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!ft_isdigit(str[0]))
	{
		if (str[i] != '-' && str[i] != '+')
			return (0);
		i += 1;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i += 1;
	}
	return (1);
}
