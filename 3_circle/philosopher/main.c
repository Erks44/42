
#include "philosopher.h"
#include <stdio.h>

int	is_number(char *str)
{
	int i = 0;

	while(str[i])
	{
		if(!(str[i] >= '0' && str[i] <= '9'))
			return(1);
		i++;
	}
	return(0);
}

int	check_args(int ac, char **av)
{
	int i = 1;
	if(!(ac <= 6 && ac >= 5))
		return(1);
	while(i < ac)
	{
		if(is_number(av[i]))
			return(1);
		i++;
	}
	return(0);
}

int main(int ac, char **av)
{
	printf("%d", check_args(ac, av));
	return(0);
}

void init_simulation(t_simulation *sim, int ac, char **av)
{
	sim -> flag = 0;
	sim -> nb_philosophers = ft_atoi(av[1]);
	sim -> time_to_die = ft_atoi(av[2]);
	sim -> time_to_eat = ft_atoi(av[3]);
	sim -> time_to_sleep = ft_atoi(av[4]);
	if(ac == 6)
	{
		sim ->	nb_times_eat = ft_atoi(av[5]);
	}
	else
		sim -> nb_times_eat = -1;
}

int init_forks(t_simulation *sim)
{
	int i = 0;
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->nb_philosophers);
	if(!sim->forks)
		return(1);
	while(i < sim->nb_philosophers)
	{
		pthread_mutex_init(&sim->forks[i], NULL);
		i++;
	}
	return(0);
}

int init_philosophers(t_simulation *sim)
{
	int i = 0;
	sim->philosophers = malloc(sizeof(t_philo) * sim->nb_philosophers);
	if(!sim->philosophers)
		return(1);
	while(i < sim->nb_philosophers)
	{
		sim->philosophers[i].id_philo = i + 1;
		sim->philosophers[i].last_meal_time = 0;
		sim->philosophers[i].times_eaten = 0;
		sim->philosophers[i].left_fork = &sim->forks[i];
		sim->philosophers[i].right_fork = &sim->forks[(i + 1) % sim->nb_philosophers];
		sim->philosophers[i].sim = sim;
		i++;
	}
	return(0);
}

