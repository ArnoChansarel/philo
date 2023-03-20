/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:45:21 by achansar          #+#    #+#             */
/*   Updated: 2023/03/20 18:25:45 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_routine(int num, char *str)
{
	struct timeval t;

	gettimeofday(&t, NULL);
	printf("%ld %d %s\n", t.tv_sec, num, str);
}

static int sleeping(int s, int num)
{
	print_routine(num, "is sleeping.");
	if (usleep(s))
	{
		perror("usleep ");
		return (1);
	}
	return (0);
}

static int eating(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	print_routine(*philo->num, "has taken a fork.");
	pthread_mutex_lock(philo->next->mutex);
	print_routine(*philo->num, "has taken a fork.");
	print_routine(*philo->num, "is eating.");
	gettimeofday(philo->last_meal, NULL);
	if (usleep(*philo->time_to_eat))
	{
		perror("usleep ");
		return (1);
	}
	pthread_mutex_unlock(philo->mutex);
	pthread_mutex_unlock(philo->next->mutex);
	return (0);
}

void    *routine(void *element)
{
	t_philo 		*philo;
	
	philo = (t_philo *)element;
	while (1)
	{
		print_routine(*philo->num, "is thinking.");
		eating(philo);
		sleeping(*philo->time_to_sleep, *philo->num);
	}
	return (NULL);
}
