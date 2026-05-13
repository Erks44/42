#include "philosopher.h"

void    eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
    	philo->last_meal_time = get_time();
    	printf("%ld %d is eating\n", get_time() - philo->sim->start_time, philo->id_philo);
    	usleep(philo->sim->time_to_eat * 1000);
    	philo->times_eaten++;
    	pthread_mutex_unlock(philo->left_fork);
    	pthread_mutex_unlock(philo->right_fork);
}

void    think(t_philo *philo)
{
    	printf("%ld %d is thinking\n", get_time() - philo->sim->start_time, philo->id_philo);
}

void	ft_sleep(t_philo *philo)
{
    	printf("%ld %d is sleeping\n", get_time() - philo->sim->start_time, philo->id_philo);
	usleep(philo->sim->time_to_sleep * 1000);
}
