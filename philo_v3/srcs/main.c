/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:40:28 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 23:40:28 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "core.h"

int	main(int argc, char **argv)
{
	t_manager	manager;

	if (init_manager(&manager, argc, argv))
	{
		printf("Invalid arguments.\n");
		return (1);
	}
}
