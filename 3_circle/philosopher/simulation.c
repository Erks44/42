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

void	philo_cycle(t_philo *philo)
{
	if (!is_dead(philo))
		eat(philo);
	if (!is_dead(philo))
		ft_sleep(philo);
	if (!is_dead(philo))
		think(philo);
}

void	*philosopher_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->sim->nb_philosophers == 1)
	{
		printf("%ld %d has taken a fork\n", get_time() - philo->sim->start_time,
			philo->id_philo);
		return (NULL);
	}
	if (philo->id_philo % 2 == 0)
		ft_usleep(philo->sim->time_to_eat / 2, philo);
	while (1)
	{
		pthread_mutex_lock(&philo->sim->sec_flag);
		if (philo->sim->flag == 1)
		{
			pthread_mutex_unlock(&philo->sim->sec_flag);
			break ;
		}
		pthread_mutex_unlock(&philo->sim->sec_flag);
		philo_cycle(philo);
	}
	return (NULL);
}

int	check_philo(t_simulation *sim, int i)
{
	pthread_mutex_lock(&sim->sec_flag);
	if (get_time()
		- sim->philosophers[i].last_meal_time > sim->time_to_die)
	{
		sim->flag = 1;
		pthread_mutex_unlock(&sim->sec_flag);
		pthread_mutex_lock(&sim->sec_aff);
		printf("%ld %d died\n", get_time() - sim->start_time,
			sim->philosophers[i].id_philo);
		pthread_mutex_unlock(&sim->sec_aff);
		return (1);
	}
	else
		pthread_mutex_unlock(&sim->sec_flag);
	return (0);
}

void	*monitor_routine(void *arg)
{
	int				i;
	t_simulation	*sim;
	int				full;

	sim = (t_simulation *)arg;
	while (sim->flag == 0)
	{
		full = 0;
		i = 0;
		while (i < sim->nb_philosophers)
		{
			if (check_philo(sim, i))
				break ;
			if (sim->philosophers[i].times_eaten >= sim->nb_times_eat)
				full++;
			i++;
		}
		if (full == sim->nb_philosophers && sim->nb_times_eat != -1)
			sim->flag = 1;
	}
	return (NULL);
}

void	start_simulation(t_simulation *sim)
{
	int			i;
	pthread_t	monitor_thread;

	sim->start_time = get_time();
	i = 0;
	while (i < sim->nb_philosophers)
	{
		sim->philosophers[i].last_meal_time = sim->start_time;
		i++;
	}
	pthread_create(&monitor_thread, NULL, monitor_routine, sim);
	i = 0;
	while (i < sim->nb_philosophers)
	{
		pthread_create(&sim->threads[i], NULL, philosopher_routine,
			&sim->philosophers[i]);
		i++;
	}
	i = 0;
	while (i < sim->nb_philosophers)
	{
		pthread_join(sim->threads[i], NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
}
