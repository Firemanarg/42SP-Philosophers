/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:21:10 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 19:21:10 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Checks if a character is a digit.
 *
 * @param c Character to be checked.
 * @return int Returns 1 if the character is a digit, 0 otherwise.
*/
int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}
