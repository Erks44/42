/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:58:33 by egjika            #+#    #+#             */
/*   Updated: 2026/05/13 23:15:41 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	eat(t_philo *philo)
{
	if (take_forks(philo))
		return;
	pthread_mutex_lock(&philo->sim->sec_aff);
	printf("%ld %d has taken a fork\n", get_time() - philo->sim->start_time, philo->id_philo);
	pthread_mutex_unlock(&philo->sim->sec_aff);
	if (is_dead(philo))
	{
		release_forks(philo);
		return;
	}
	pthread_mutex_lock(&philo->sim->sec_aff);
	printf("%ld %d has taken a fork\n", get_time() - philo->sim->start_time, philo->id_philo);
	pthread_mutex_unlock(&philo->sim->sec_aff);
	pthread_mutex_lock(&philo->sim->sec_flag);
    	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->sim->sec_flag);
	pthread_mutex_lock(&philo->sim->sec_aff);
    	printf("%ld %d is eating\n", get_time() - philo->sim->start_time, philo->id_philo);
	pthread_mutex_unlock(&philo->sim->sec_aff);
    	usleep(philo->sim->time_to_eat * 1000);
    	philo->times_eaten++;
	release_forks(philo);
}

void    think(t_philo *philo)
{
	if (is_dead(philo))
		return;
	pthread_mutex_lock(&philo->sim->sec_aff);
    	printf("%ld %d is thinking\n", get_time() - philo->sim->start_time, philo->id_philo);
	pthread_mutex_unlock(&philo->sim->sec_aff);
}

void	ft_sleep(t_philo *philo)
{
	if (is_dead(philo))
		return;
	pthread_mutex_lock(&philo->sim->sec_aff);
    	printf("%ld %d is sleeping\n", get_time() - philo->sim->start_time, philo->id_philo);
	pthread_mutex_unlock(&philo->sim->sec_aff);
	usleep(philo->sim->time_to_sleep * 1000);
}
