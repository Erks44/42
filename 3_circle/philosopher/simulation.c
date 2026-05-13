#include <sys/time.h>

void    *philosopher_routine(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    while(philo->sim->flag == 0)
    {
        eat(philo);
        ft_sleep(philo);
        think(philo);
    }
    return(NULL);
}

void start_simulation(t_simulation *sim)
{
    int i = 0;
    sim->start_time = get_time();
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
}
