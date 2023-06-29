/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-q <lsilva-q@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:30:11 by lsilva-q          #+#    #+#             */
/*   Updated: 2023/04/20 15:30:11 by lsilva-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Submitted by : Ashutosh Soni

// Header file include
#include <bits/stdc++.h>
#include <pthread.h>
#include <unistd.h>
using namespace std;

#define N 10
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum + 4) % N
#define RIGHT (phnum + 1) % N

// Philosopher index
int phil[N];
int times = 200;

class monitor {

	// state of the philosopher
	int state[N];

	// Philosopher condition variable
	pthread_cond_t phcond[N];

	// mutex variable for synchronization
	pthread_mutex_t condLock;

public:
	// Test for the desired condition
	// i.e. Left and Right philosopher are not reading
	void test(int phnum)
	{

		if (state[(phnum + 1) % 5] != EATING
			and state[(phnum + 4) % 5] != EATING
			and state[phnum] == HUNGRY) {
			state[phnum] = EATING;

			pthread_cond_signal(&phcond[phnum]);
		}
	}

	// Take Fork function
	void take_fork(int phnum)
	{

		pthread_mutex_lock(&condLock);

		// Indicates it is hungry
		state[phnum] = HUNGRY;

		// test for condition
		test(phnum);

		// If unable to eat.. wait for the signal
		if (state[phnum] != EATING) {
			pthread_cond_wait(&phcond[phnum], &condLock);
		}
		cout << "Philosopher " << phnum << " is Eating"
			<< endl;

		pthread_mutex_unlock(&condLock);
	}

	// Put Fork function
	void put_fork(int phnum)
	{

		pthread_mutex_lock(&condLock);

		// Indicates that I am thinking
		state[phnum] = THINKING;

		test(RIGHT);
		test(LEFT);

		pthread_mutex_unlock(&condLock);
	}

	// constructor
	monitor()
	{

		for (int i = 0; i < N; i++) {
			state[i] = THINKING;
		}

		for (int i = 0; i < N; i++) {
			pthread_cond_init(&phcond[i], NULL);
		}

		pthread_mutex_init(&condLock, NULL);
	}

	// destructor
	~monitor()
	{

		for (int i = 0; i < N; i++) {
			pthread_cond_destroy(&phcond[i]);
		}

		pthread_mutex_destroy(&condLock);
	}
}

// Global Object of the monitor
phil_object;

void* philosopher(void* arg)
{
	int c = 0;
	while (c < times) {
		int i = *(int*)arg;
		sleep(1);
		phil_object.take_fork(i);
		sleep(0.5);
		phil_object.put_fork(i);
		c++;
	}
}

int main()
{

	// Declaration...
	pthread_t thread_id[N];
	pthread_attr_t attr;

	// Initialization...
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,
								PTHREAD_CREATE_JOINABLE);

	for (int i = 0; i < N; i++) {
		phil[i] = i;
	}

	// Creating...
	for (int i = 0; i < N; i++) {
		pthread_create(&thread_id[i], &attr, philosopher,
					&phil[i]);
		cout << "Philosopher " << i + 1 << " is thinking..."
			<< endl;
	}

	// Joining....
	for (int i = 0; i < N; i++) {
		pthread_join(thread_id[i], NULL);
	}

	// Destroying
	pthread_attr_destroy(&attr);
	pthread_exit(NULL);

	return 0;
}




// #include <stdio.h>
// #include <pthread.h>
// #include "philo.h"
// #include "manager.h"

// int	main(int argc, char *argv[])
// {
// 	t_manager	manager;

// 	start_simulation(&manager, argc, argv);
// }




// int	main(void)
// {
// 	t_times	*max_durations;
// 	// t_philo	*philos[10];
// 	// t_philo *philo;
// 	t_philo	**philos;
// 	int		i;

// 	// max_durations = (t_times){.thinking = 2000, .eating = 200, .sleeping = 600};
// 	max_durations = new_times(
// 						new_time_by_mstime(2000),
// 						new_time_by_mstime(200),
// 						new_time_by_mstime(600));
// 	philos = new_philo_array(10, max_durations);
// 	// i = 0;
// 	// while (i < 10)
// 	// {
// 	// 	philo = new_philo(i, max_durations);
// 	// 	philos[i] = philo;
// 	// 	pthread_create(&(philo->id), NULL, init_philo_thread, philo);
// 	// 	i += 1;
// 	// }
// 	pthread_exit(NULL);
// }



























// ----------------------------------------------------------

// void	*print_thread_id(void *arg)
// {
// 	long	*id;

// 	id = (long *) arg;
// 	printf("Thread ID: %ld\n", *id);
// }

// int	main(void)
// {
// 	pthread_t	thr_id;

// 	pthread_create(&thr_id, NULL, print_thread_id, &thr_id);
// 	pthread_exit(NULL);
// }
