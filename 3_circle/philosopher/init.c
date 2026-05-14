/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:58:28 by egjika            #+#    #+#             */
/*   Updated: 2026/05/13 20:48:32 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_simulation(t_simulation *sim, int ac, char **av)
{
	pthread_mutex_init(&sim->sec_flag, NULL);
	pthread_mutex_init(&sim->sec_aff, NULL);
	sim->flag = 0;
	sim->nb_philosophers = ft_atoi(av[1]);
	sim->time_to_die = ft_atoi(av[2]);
	sim->time_to_eat = ft_atoi(av[3]);
	sim->time_to_sleep = ft_atoi(av[4]);
	sim->threads = malloc(sizeof(pthread_t) * sim->nb_philosophers + 1);
	if (ac == 6)
	{
		sim->nb_times_eat = ft_atoi(av[5]);
	}
	else
		sim->nb_times_eat = -1;
}

int	init_forks(t_simulation *sim)
{
	int	i;

	i = 0;
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->nb_philosophers);
	if (!sim->forks)
		return (1);
	while (i < sim->nb_philosophers)
	{
		pthread_mutex_init(&sim->forks[i], NULL);
		i++;
	}
	return (0);
}

int	init_philosophers(t_simulation *sim)
{
	int	i;

	i = 0;
	sim->philosophers = malloc(sizeof(t_philo) * sim->nb_philosophers);
	if (!sim->philosophers)
		return (1);
	while (i < sim->nb_philosophers)
	{
		sim->philosophers[i].id_philo = i + 1;
		sim->philosophers[i].last_meal_time = 0;
		sim->philosophers[i].times_eaten = 0;
		sim->philosophers[i].left_fork = &sim->forks[i];
		sim->philosophers[i].right_fork = &sim->forks[(i + 1)
			% sim->nb_philosophers];
		sim->philosophers[i].sim = sim;
		i++;
	}
	return (0);
}

void	cleanup(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->nb_philosophers)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&sim->sec_aff);
	pthread_mutex_destroy(&sim->sec_flag);
	free(sim->threads);
	free(sim->philosophers);
	free(sim->forks);
}
