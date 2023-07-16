/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:32:10 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/15 18:32:10 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static int	is_argv_valid(t_manager *manager, int argc, char **argv);
static void	assign_argv(t_manager *manager, int argc, char **argv);

/**
 * @brief Initializes the manager structure.
 *
 * @param manager Pointer to the manager structure.
 * @param argc Number of arguments passed to the program.
 * @param argv Array of arguments passed to the program.
 *
 * @return int Returns 0 if the manager was initialized successfully,
 * -1 otherwise.
*/
int	init_manager(t_manager *manager, int argc, char **argv)
{
	if (!is_argv_valid(manager, argc, argv))
		return (-1);
	assign_argv(manager, argc, argv);
	manager->forks = malloc(sizeof(pthread_mutex_t) * manager->philos_count);
	manager->philos = malloc(sizeof(t_philo) * manager->philos_count);
	manager->can_continue = 1;
	manager->eat_done_count = 0;
	manager->someone_died = 0;
	manager->start_time = get_mstime();
	pthread_mutex_init(&manager->sync_mutex, NULL);
	pthread_mutex_init(&manager->print_mutex, NULL);
	pthread_mutex_init(&manager->continue_check_mutex, NULL);
	pthread_mutex_init(&manager->forks_mutex, NULL);
	pthread_create(&manager->manager_thread, NULL, manager_routine, manager);
}

/**
 * @brief Checks if the arguments passed to the program are valid.
 *
 * @param manager Pointer to the manager structure.
 * @param argc Number of arguments passed to the program.
 *
 * @return int Returns 1 if the arguments are valid, 0 otherwise.
*/
static int	is_argv_valid(t_manager *manager, int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		i += 1;
	}
	return (1);
}

/**
 * @brief Assigns the arguments passed to the program to the manager structure.
 *
 * @param manager Pointer to the manager structure.
 * @param argc Number of arguments passed to the program.
 * @param argv Array of arguments passed to the program.
 *
 * @return void
*/
static void	assign_argv(t_manager *manager, int argc, char **argv)
{
	manager->philos_count = ft_atoi(argv[1]);
	manager->time_to_die = ft_atoll(argv[2]);
	manager->time_to_eat = ft_atoll(argv[3]);
	manager->time_to_sleep = ft_atoll(argv[4]);
	if (argc == 6)
		manager->meals_count = ft_atoi(argv[5]);
	else
		manager->meals_count = -1;
}
