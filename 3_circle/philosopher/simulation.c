/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:58:13 by egjika            #+#    #+#             */
/*   Updated: 2026/05/13 22:49:12 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	if(philo->sim->nb_philosophers == 1)
	{
		printf("%ld %d has taken a fork\n", get_time() - philo->sim->start_time, philo->id_philo);
		return(NULL);
	}
	while(1)
	{
		pthread_mutex_lock(&philo->sim->sec_flag);
		if(philo->sim->flag == 1)
		{
			pthread_mutex_unlock(&philo->sim->sec_flag);
			break;
		}
		pthread_mutex_unlock(&philo->sim->sec_flag);
		if(philo->sim->flag != 1)
			eat(philo);
		if(philo->sim->flag != 1)
			ft_sleep(philo);
		if(philo->sim->flag != 1)
			think(philo);
	}
	return(NULL);
}

void	*monitor_routine(void *arg)
{
	int	i;
	t_simulation	*sim;
	int	full;

	sim = (t_simulation *)arg;
	i = 0;
	while(sim->flag == 0)
	{
		full = 0;
		i = 0;
		while(i < sim->nb_philosophers)
		{
			pthread_mutex_lock(&sim->sec_flag);
			if(get_time() - sim->philosophers[i].last_meal_time > sim->time_to_die)
			{
				sim->flag = 1;
				pthread_mutex_unlock(&sim->sec_flag);
				pthread_mutex_lock(&sim->sec_aff);
				printf("%ld %d died\n", get_time() - sim->start_time, sim->philosophers[i].id_philo);
				pthread_mutex_unlock(&sim->sec_aff);
				break;
			}
			else
				pthread_mutex_unlock(&sim->sec_flag);
			if(sim->philosophers[i].times_eaten >= sim->nb_times_eat)
				full++;
			i++;
		}
		if (full == sim->nb_philosophers && sim->nb_times_eat != -1)
			sim->flag = 1;
	}
	return(NULL);
}

void	start_simulation(t_simulation *sim)
{
	int	i;
	pthread_t	monitor_thread;

	sim->start_time = get_time();
	i = 0;
	while(i < sim->nb_philosophers)
	{
		sim->philosophers[i].last_meal_time = sim->start_time;
		i++;
	}
	pthread_create(&monitor_thread, NULL, monitor_routine, sim);
	i = 0;
	while(i < sim->nb_philosophers)
	{
		pthread_create(&sim->threads[i], NULL, philosopher_routine, &sim->philosophers[i]);
		i++;
	}
	i = 0;
	while(i < sim->nb_philosophers)
	{
		pthread_join(sim->threads[i], NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
}
