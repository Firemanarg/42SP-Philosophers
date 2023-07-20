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

void	init_philo(t_philo *philo, int id, t_args *args)
{
	int	left_fork_index;
	int	right_fork_index;
	int	index;

	philo->args = args;
	philo->id = id;
	philo->last_meal = curr_time();
	right_fork_index = 0;
	left_fork_index = 0;
	if (args->philos_count > 1)
	{
		index = id - 1;
		right_fork_index = min(index, (index + 1) % args->philos_count);
		left_fork_index = max(index, (index + 1) % args->philos_count);
	}
	philo->left_fork = args->forks + left_fork_index;
	philo->right_fork = args->forks + right_fork_index;
	philo->meals = 0;
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
		pthread_mutex_init(args->forks + i, NULL);
		init_philo(&args->philos[i], i + 1, args);
		i += 1;
	}
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

int	safeget_int(int *var, pthread_mutex_t *mutex)
{
	int	result;

	pthread_mutex_lock(mutex);
	result = *var;
	pthread_mutex_unlock(mutex);
	return (result);
}

void	safeset_int(int *var, int value, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*var = value;
	pthread_mutex_unlock(mutex);
}

// int	can_continue_simulation(t_philo *philo)
// {
// 	int	result;

// 	pthread_mutex_lock(&philo->args->sync_mutex);
// 	result = philo->args->can_run;
// 	pthread_mutex_unlock(&philo->args->sync_mutex);
// 	return (result);
// }

// void	set_simulation_status(t_philo *philo, int status)
// {
// 	pthread_mutex_lock(&philo->args->sync_mutex);
// 	philo->args->can_run = status;
// 	pthread_mutex_unlock(&philo->args->sync_mutex);
// }
