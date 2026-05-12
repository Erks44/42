/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philospher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 18:28:00 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/05/11 14:27:54 by errikosgjik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

int	ft_atoi(char *str);

typedef struct s_philo
{
	int	id_philo;
	long	last_meal_time;
	long	times_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t *right_fork;
	t_simulation	*sim;
}	t_philo;

typedef struct s_simulation
{
	int	nb_philosophers;
	int	time_to_eat;
	int	time_to_die;
	int	time_to_sleep;
	int	nb_times_eat;
	pthread_mutex_t	*forks;
	t_philo	*philosphers;
	long	start_time;
	int	flag;
	pthread_mutex_t sec_flag;
	pthread_mutex_t sec_aff;
}	t_simulation;

#endif
