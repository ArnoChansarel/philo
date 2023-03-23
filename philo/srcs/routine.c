/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:45:21 by achansar          #+#    #+#             */
/*   Updated: 2023/03/22 17:45:55 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time_mili(void)
{
	struct timeval	time;
	long			time_m;

	gettimeofday(&time, NULL);
	time_m = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_m);
}

void	print_routine(t_philo *philo, char *str)
{
	long	time;

	time = get_time_mili();
	pthread_mutex_lock(philo->print);
	printf("%ld %d %s\n", time - *philo->start, *philo->num, str);
	pthread_mutex_unlock(philo->print);
}

static int	sleeping(t_philo *philo)
{
	print_routine(philo, "is sleeping.");
	if (usleep(*philo->time_to_sleep * 1000))
	{
		perror("usleep ");
		return (1);
	}
	return (0);
}

static int	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	print_routine(philo, "has taken a fork.");
	pthread_mutex_lock(philo->next->mutex);
	print_routine(philo, "has taken a fork.");
	print_routine(philo, "is eating.");
	philo->last_meal = get_time_mili();
	philo->meal += 1;
	if (usleep(*philo->time_to_eat * 1000))
	{
		perror("usleep ");
		return (1);
	}
	pthread_mutex_unlock(philo->mutex);
	pthread_mutex_unlock(philo->next->mutex);
	return (0);
}

void	*routine(void *element)
{
	t_philo	*philo;

	philo = (t_philo *)element;
	while (1)
	{
		print_routine(philo, "is thinking.");
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}
