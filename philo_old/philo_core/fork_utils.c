/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:31:56 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/04/20 15:31:56 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	new_fork(void)
{
	t_fork	_fork;

	_fork = (t_fork){.owner_index = -1, .is_available = AVAILABLE};
	return (_fork);
}

void	release_fork(t_fork *_fork)
{
	_fork->owner_index = -1;
	_fork->is_available = AVAILABLE;
}

void	take_fork(t_fork *_fork, int owner_index)
{
	_fork->owner_index = owner_index;
	_fork->is_available = UNAVAILABLE;
}
