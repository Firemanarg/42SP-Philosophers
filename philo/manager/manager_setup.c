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

static void	init_forks(t_manager *manager);
static void	init_philos(t_manager *manager);
static void	link_philos(t_manager *manager);

/* Parei aqui. Finalizei a parte de inicialização do manager, incluindo
 * a inicialização dos filósofos e dos garfos. Falta agora a parte de
 * inicialização das threads e criar a função de loop dos filósofos.
 * Falta implementar também as funções de teste para os filósofos, put_fork
 * e take_fork.
*/

int	init_manager(t_manager *manager, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	manager->philo_count = ft_atoi(argv[1]);
	manager->fork_count = manager->philo_count - 1;
	if (manager->philo_count == 1)
		manager->fork_count = 1;
	if (manager->philo_count < 1)
		return (1);
	manager->philos = malloc(sizeof(t_philo) * manager->philo_count);
	manager->forks = malloc(sizeof(t_fork) * manager->fork_count);
	manager->time_to[DIE] = ft_atoll(argv[2]);
	manager->time_to[EAT] = ft_atoll(argv[3]);
	manager->time_to[SLEEP] = ft_atoll(argv[4]);
	init_forks(manager);
	init_philos(manager);
	return (0);
}

static void	init_forks(t_manager *manager)
{
	int	i;

	i = 0;
	while (i < manager->fork_count)
	{
		manager->forks[i].index = i + 1;
		manager->forks[i].state = AVAILABLE;
		i += 1;
	}
}

static void	init_philos(t_manager *manager)
{
	int	right_fork_index;
	int	left_fork_index;
	int	fork_count;
	int	i;

	fork_count = manager->fork_count;
	i = 0;
	while (i < manager->philo_count)
	{
		manager->philos[i].index = i + 1;
		manager->philos[i].eat_count = 0;
		right_fork_index = (i + 1) % fork_count;
		left_fork_index = (i + fork_count - 1) % fork_count;
		manager->philos[i].left_fork = manager->forks + left_fork_index;
		manager->philos[i].right_fork = manager->forks + right_fork_index;
		manager->philos[i].last_eat = 0;
		manager->philos[i].last_sleep = 0;
		manager->philos[i].last_think = 0;
		manager->philos[i].state = THINKING;
		i += 1;
	}
	link_philos(manager);
}

static void	link_philos(t_manager *manager)
{
	int	right_philo_index;
	int	left_philo_index;
	int	philo_count;
	int	i;

	philo_count = manager->philo_count;
	i = 0;
	while (i < manager->philo_count)
	{
		right_philo_index = (i + 1) % philo_count;
		left_philo_index = (i + philo_count - 1) % philo_count;
		manager->philos[i].left_philo = manager->philos + left_philo_index;
		manager->philos[i].right_philo = manager->philos + right_philo_index;
		i += 1;
	}
}
