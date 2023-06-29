/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:35:22 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/04/20 15:35:22 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

/* Allocate and initialize an array of t_philo, of size 'amount'.
 */
t_philo	**new_philo_array(int amount, t_times *max_durations)
{
	t_philo	**philos;
	t_philo	*philo;
	int		i;

	philos = malloc(sizeof(t_philo) * amount);
	i = 0;
	while (i < amount)
	{
		philo = new_philo(i, max_durations);
		*(philos + 1) = philo;
		pthread_create(&(philo->id), NULL, init_philo_thread, philo);
		i += 1;
	}
	return (philos);
}

	// if (argc < MIN_ARGC || argc > MAX_ARGC)
	// {
	// 	printf("Invalid arguments count! Finishing program.\n")
	// 	return (NULL);
	// }
t_table_args	*create_table_args(int argc, int argv)
{
	t_table_args	*args;


}
