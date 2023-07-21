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
static void	start_simulation(t_philo_king *king);
static void	clean_all(t_philo_king *king);

int	main(int argc, char **argv)
{
	t_philo_king	king;
	t_args			args;

	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments.\n");
		return (1);
	}
	init_args(&args, argc, argv);
	init_philo_king(&king, &args);
	start_simulation(&king);
	clean_all(&king);
}

static void	init_args(t_args *args, int argc, char **argv)
{
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
}

static void	start_simulation(t_philo_king *king)
{
	int	i;

	i = 0;
	while (i < king->args->philos_count)
	{
		pthread_create(&king->philos[i].thread, NULL,
			philo_routine, &king->philos[i]);
		i += 1;
	}
	pthread_create(&king->thread, NULL, philo_king_routine, king);
}

static void	clean_all(t_philo_king *king)
{
	int	i;

	i = 0;
	while (i < king->args->philos_count)
	{
		pthread_join(king->philos[i].thread, NULL);
		pthread_mutex_destroy(king->forks + i);
		i += 1;
	}
	pthread_join(king->thread, NULL);
	pthread_mutex_destroy(&king->args->out_mutex);
	pthread_mutex_destroy(&king->args->sync_mutex);
	free(king->philos);
	free(king->forks);
}
