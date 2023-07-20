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

	// Mudar as atribuições para philo->args = args
	// Manter todos os argumentos em uma variável só, e copiar somente o
	// endereco de args para philo->args
	philo->args = args;
	philo->id = id;
	philo->last_meal = curr_time();
	// right_fork_index = (index + 1) % args->philos_count;
	// left_fork_index = (index + args->philos_count - 1) % args->philos_count;
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
	// philo->can_run = &args->can_run;
	// philo->out_mutex = &args->out_mutex;
	// philo->sync_mutex = &args->sync_mutex;
	// philo->time_to_die = args->time_to_die;
	// philo->time_to_eat = args->time_to_eat;
	// philo->time_to_sleep = args->time_to_sleep;
	// philo->min_meals = args->min_meals;
}

void	print(t_philo *philo, char *msg)
{
	if (philo->args->can_run)
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

int	can_continue_simulation(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->args->sync_mutex);
	result = philo->args->can_run;
	pthread_mutex_unlock(&philo->args->sync_mutex);
	return (result);
}

void	set_simulation_status(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->args->sync_mutex);
	philo->args->can_run = status;
	pthread_mutex_unlock(&philo->args->sync_mutex);
}
