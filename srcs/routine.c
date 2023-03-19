/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:45:21 by achansar          #+#    #+#             */
/*   Updated: 2023/03/19 17:37:37 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int sleeping(struct timeval current_time, int s, int num)
{
	gettimeofday(&current_time, NULL);
	printf("%ld %d is sleeping.\n", current_time.tv_sec, num);
	if (usleep(s))
	{
		perror("usleep ");
		return (1);
	}
	return (0);
}

static int thinking(struct timeval current_time, int num)
{
	gettimeofday(&current_time, NULL);
	printf("%ld %d is thinking.\n", current_time.tv_sec, num);
	return (0);
}

static int eating(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex);
	gettimeofday(&philo->current_time, NULL);
	printf("%ld %d has taken a fork.\n", philo->current_time.tv_sec, *philo->num);
	pthread_mutex_lock(philo->next->mutex);
	gettimeofday(&philo->current_time, NULL);
	printf("%ld %d has taken a fork.\n", philo->current_time.tv_sec, *philo->num);
	gettimeofday(&philo->current_time, NULL);
	printf("%ld %d is eating.\n", philo->current_time.tv_sec, *philo->num);
	if (usleep(philo->time_to_eat))
	{
		perror("usleep ");
		return (1);
	}
	pthread_mutex_unlock(philo->mutex);
	pthread_mutex_unlock(philo->next->mutex);
	return (1);
	return (0);
}

void    *routine(void *element)
{
	t_philo 		*philo;
	
	philo = (t_philo *)element;
	// print_list(philo, 1);
	while (philo->is_alive)
	{
		thinking(philo->current_time, *philo->num);
		eating(philo);
		sleeping(philo->current_time, philo->time_to_sleep, *philo->num);
	}
	return (NULL);
}
