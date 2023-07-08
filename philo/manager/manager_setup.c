/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:46:01 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/06/28 15:46:01 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manager.h"

// static void	init_forks(t_manager *manager);
// static void	init_philos(t_manager *manager);
// static void	init_threads(t_manager *manager);
static void	init_forks_and_philos(t_manager *manager);

int	init_manager(t_manager *manager, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	manager->philo_count = ft_atoi(argv[1]);
	manager->fork_count = manager->philo_count;
	if (manager->philo_count == 1)
		manager->fork_count = 1;
	if (manager->philo_count < 1)
		return (1);
	manager->philos = malloc(sizeof(t_philo) * manager->philo_count);
	manager->forks = malloc(sizeof(t_fork) * manager->fork_count);
	manager->time_to_die = ft_atoll(argv[2]);
	manager->time_to_eat = ft_atoll(argv[3]);
	manager->time_to_sleep = ft_atoll(argv[4]);
	printf("Philosophers: %d\n", manager->philo_count);
	printf("Forks: %d\n", manager->fork_count);
	manager->start_time = get_current_mstime();
	// init_forks(manager);
	pthread_mutex_init(&(manager->mutex), NULL);
	init_forks_and_philos(manager);
	pthread_create(&(manager->monitor), NULL, &monitor_routine,
		(void *) manager);
	return (0);
}

static void	init_forks_and_philos(t_manager *manager)
{
	t_philo		*philo;
	t_fork		*fork;
	int			i;

	pthread_mutex_init(&(manager->mutex), NULL);
	i = 0;
	while (i < manager->philo_count)
	{
		fork = manager->forks + i;
		fork->index = i + 1;
		fork->status = AVAILABLE;
		pthread_mutex_init(&(fork->mutex), NULL);
		philo = manager->philos + i;
		init_philo(philo, manager, i);
		philo_set_status(philo, THINKING);
		pthread_create(&(philo->thread), NULL, &philo_routine, (void *) philo);
		i += 1;
	}
}

// static void	init_forks(t_manager *manager)
// {
// 	int	i;

// 	i = 0;
// 	while (i < manager->fork_count)
// 	{
// 		manager->forks[i].index = i + 1;
// 		manager->forks[i].status = AVAILABLE;
// 		i += 1;
// 	}
// }

// static void	init_philos(t_manager *manager)
// {
// 	int	right_fork_index;
// 	int	left_fork_index;
// 	int	fork_count;
// 	int	i;

// 	fork_count = manager->fork_count;
// 	i = 0;
// 	while (i < manager->philo_count)
// 	{
// 		manager->philos[i].is_running = 1;
// 		manager->philos[i].index = i + 1;
// 		manager->philos[i].eat_count = 0;
// 		manager->philos[i].manager_eat_done_count = &(manager->eat_done_count);
// 		manager->philos[i].manager_death_flag = &(manager->death_flag);
// 		right_fork_index = (i + 1) % fork_count;
// 		left_fork_index = (i + fork_count - 1) % fork_count;
// 		manager->philos[i].left_fork = manager->forks + left_fork_index;
// 		manager->philos[i].right_fork = manager->forks + right_fork_index;
// 		manager->philos[i].time_to_die = manager->time_to_die;
// 		manager->philos[i].time_to_eat = manager->time_to_eat;
// 		manager->philos[i].time_to_sleep = manager->time_to_sleep;
// 		manager->philos[i].last_fork_take = 0;
// 		manager->philos[i].last_eat = get_current_mstime();
// 		manager->philos[i].last_sleep = get_current_mstime();
// 		manager->philos[i].status = NONE;
// 		manager->philos[i].prev_status = NONE;
// 		i += 1;
// 	}
// 	init_threads(manager);
// }

// static void	init_threads(t_manager *manager)
// {
// 	t_philo		*philo;
// 	pthread_t	*philo_thread;
// 	int			i;

// 	pthread_mutex_init(&(manager->mutex), NULL);
// 	i = 0;
// 	while (i < manager->philo_count)
// 	{
// 		philo = manager->philos + i;
// 		philo->start_time = manager->start_time;
// 		philo_set_status(philo, THINKING);
// 		manager->philos[i].mutex = &(manager->mutex);
// 		philo_thread = &(philo->thread);
// 		pthread_create(philo_thread, NULL, &philo_routine, (void *) philo);
// 		i += 1;
// 	}
// 	pthread_create(&(manager->monitor), NULL, &monitor_routine,
// 		(void *) manager);
// }
