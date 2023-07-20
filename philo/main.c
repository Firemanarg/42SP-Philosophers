/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 08:49:28 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/18 08:49:28 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_args(t_args *args, int argc, char **argv);
static void	init_philos(t_args *args);
static void	start_simulation(t_args *args);
static void	clean_all(t_args *args);

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments.\n");
		return (1);
	}
	init_args(&args, argc, argv);
	init_philos(&args);
	start_simulation(&args);
	clean_all(&args);
}

static void	init_args(t_args *args, int argc, char **argv)
{
	int	i;

	args->philos_count = (int) ft_atoll(argv[1]);
	args->time_to_die = ft_atoll(argv[2]);
	args->time_to_eat = ft_atoll(argv[3]);
	args->time_to_sleep = ft_atoll(argv[4]);
	if (argc == 6)
		args->min_meals = (int) ft_atoll(argv[5]);
	else
		args->min_meals = -1;
	pthread_mutex_init(&args->out_mutex, NULL);
	pthread_mutex_init(&args->sync_mutex, NULL);
	args->completed_meals_count = 0;
	args->can_run = 1;
	args->philos = malloc(sizeof(t_philo) * args->philos_count);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->philos_count);
	i = 0;
	while (i < args->philos_count)
	{
		pthread_mutex_init(args->forks + i, NULL);
		i += 1;
	}
}

static void	init_philos(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philos_count)
	{
		init_philo(&args->philos[i], i + 1, args);
		i += 1;
	}
}

static void	start_simulation(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philos_count)
	{
		pthread_create(&args->philos[i].thread, NULL,
						philo_routine, &args->philos[i]);
		i += 1;
	}
}

static void	clean_all(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philos_count)
	{
		pthread_join(args->philos[i].thread, NULL);
		pthread_mutex_destroy(args->forks + i);
		i += 1;
	}
	pthread_mutex_destroy(&args->out_mutex);
	pthread_mutex_destroy(&args->sync_mutex);
	free(args->philos);
	free(args->forks);
}
