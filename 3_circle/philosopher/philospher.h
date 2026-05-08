/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philospher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: errikosgjika <errikosgjika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 18:28:00 by errikosgjik       #+#    #+#             */
/*   Updated: 2026/05/08 13:56:16 by errikosgjik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	time_to_eat;
	int	time_to_die;
	int	time_to_sleep;
	int	numbers_of_philosophers;
	pthread_mutex_t	*forks;
	t_philo	*philosphers;
	int	flag;
	pthread_mutex_t sec_flag;
}	t_simulation;
