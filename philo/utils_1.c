/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 08:35:49 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/07/18 08:35:49 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *philo, int id, t_philo_king *king)
{
	int	left_fork_index;
	int	right_fork_index;
	int	index;

	right_fork_index = 0;
	left_fork_index = 0;
	if (king->args->philos_count > 1)
	{
		index = (id) % king->args->philos_count;
		right_fork_index = id - 1;
		if (id - 1 < index)
			right_fork_index = index;
		left_fork_index = id - 1;
		if (id - 1 > index)
			left_fork_index = index;
	}
	*philo = (t_philo){.id = id, .args = king->args, .last_meal = curr_time(),
		.left_fork = king->forks + left_fork_index,
		.right_fork = king->forks + right_fork_index,
		.can_run = TRUE, .is_alive = TRUE, .has_ate_enough = FALSE};
	pthread_mutex_init(&philo->mutex, NULL);
}

void	init_philo_king(t_philo_king *king, t_args *args)
{
	int	i;

	king->completed_meals_count = 0;
	king->args = args;
	king->philos = malloc(sizeof(t_philo) * args->philos_count);
	king->forks = malloc(sizeof(pthread_mutex_t) * args->philos_count);
	i = 0;
	while (i < args->philos_count)
	{
		pthread_mutex_init(king->forks + i, NULL);
		init_philo(&king->philos[i], i + 1, king);
		i += 1;
	}
}

void	*stop_all_philos(t_philo_king *king)
{
	int	i;

	i = 0;
	while (i < king->args->philos_count)
	{
		safeset_int(&king->philos[i].can_run, STOPPED, &king->philos[i].mutex);
		i += 1;
	}
	return (NULL);
}

void	print(t_philo *philo, char *msg)
{
	int	run_state;

	run_state = safeget_int(&philo->can_run, &philo->args->sync_mutex);
	if (run_state == RUNNING)
	{
		pthread_mutex_lock(&philo->args->out_mutex);
		printf("%8lld %d %s\n", curr_time(), philo->id, msg);
		pthread_mutex_unlock(&philo->args->out_mutex);
	}
}

long long	ft_atoll(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = 1 * (*str == '+') - 1 * (*str == '-');
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
