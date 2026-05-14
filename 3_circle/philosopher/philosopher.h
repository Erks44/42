/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 18:28:00 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/05/13 22:46:50 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_simulation	t_simulation;

typedef struct s_philo
{
	int						id_philo;
	long					last_meal_time;
	long					times_eaten;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	t_simulation			*sim;
}							t_philo;

typedef struct s_simulation
{
	int						nb_philosophers;
	int						time_to_eat;
	int						time_to_die;
	int						time_to_sleep;
	int						nb_times_eat;
	pthread_mutex_t			*forks;
	t_philo					*philosophers;
	long					start_time;
	int						flag;
	pthread_mutex_t			sec_flag;
	pthread_mutex_t			sec_aff;
	pthread_t				*threads;
}							t_simulation;

// utils.c
long						get_time(void);
int							is_dead(t_philo *philo);
void						release_forks(t_philo *philo);
int							take_forks(t_philo *philo);
void						ft_usleep(long ms, t_philo *philo);

// init.c
void						init_simulation(t_simulation *sim, int ac,
								char **av);
int							init_forks(t_simulation *sim);
int							init_philosophers(t_simulation *sim);
void						cleanup(t_simulation *sim);

// actions.c
void						eat(t_philo *philo);
void						think(t_philo *philo);
void						ft_sleep(t_philo *philo);

// simulation.c
void						*philosopher_routine(void *arg);
void						*monitor_routine(void *arg);
void						start_simulation(t_simulation *sim);

// main.c
int							is_number(char *str);
int							ft_atoi(char *str);
int							check_args(int ac, char **av);

#endif
