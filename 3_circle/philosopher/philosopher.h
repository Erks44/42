/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:29:06 by egjika            #+#    #+#             */
/*   Updated: 2026/02/24 10:38:41 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // printf
#include <stdlib.h> // malloc free
#include <unistd.h> // write, usleep
#include <stdbool.h>
#include <pthread.h> // mutex : iniit destroy lock unlock
		     // threads : create join detachT
#include <sys/time.h> // getttimeofday
#include <limits.h> // INT_MAX

typedef	pthread_mutex_t t_mtx;

typedef struct s_fork
{
	t_mtx	fork;
	int	fork_id;
}	t_fork;

typedef struct s_philo
{
	int	id;
	long	meals_counter;
	bool	full;
	long	last_meal_time;
	t_fork	*left_fork;
	t_fork	*right_fork;
	pthread_t	thread_id;
}	t_philo;

typedef struct s_table
{
	long	philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_limit_meals;
	long	start_simulation;
	bool	end_simulation;
	t_fork	*forks;
	t_philo	*philos;
}
