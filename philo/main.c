/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:38:41 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/06/28 15:38:41 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "manager.h"

int	main(int argc, char **argv)
{
	t_manager	manager;

	printf("Simulation started: %lld\n", get_current_mstime());
	if (init_manager(&manager, argc, argv))
	{
		printf("Error: invalid arguments.\n");
		return (1);
	}
}
