/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egjika <egjika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:58:20 by egjika            #+#    #+#             */
/*   Updated: 2026/05/13 22:42:07 by egjika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long get_time(void)
{
	struct timeval tv;
    	gettimeofday(&tv, NULL);
    	return(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int    is_dead(t_philo *philo)
{
	int dead;

	pthread_mutex_lock(&philo->sim->sec_flag);
	dead = philo->sim->flag;
	pthread_mutex_unlock(&philo->sim->sec_flag);
	return(dead);
}

void    release_forks(t_philo *philo)
{
   	pthread_mutex_unlock(philo->left_fork);
   	pthread_mutex_unlock(philo->right_fork);
}

int    take_forks(t_philo *philo)
{
    	pthread_mutex_lock(philo->left_fork);
    	if(is_dead(philo))
    	{
        	pthread_mutex_unlock(philo->left_fork);
        	return(1);
    	}
    	pthread_mutex_lock(philo->right_fork);
    	if(is_dead(philo))
    	{
        	release_forks(philo);
        	return(1);
    	}
    	return(0);
}
