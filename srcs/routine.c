/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:45:21 by achansar          #+#    #+#             */
/*   Updated: 2023/03/17 17:45:12 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int sleeping(struct timeval current_time, int s, int num)
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

int thinking(struct timeval current_time, int num)
{
	gettimeofday(&current_time, NULL);
	printf("%ld %d is thinking.\n", current_time.tv_sec, num);
	return (0);
}

int eating(struct timeval current_time, int s, int num)
{
    gettimeofday(&current_time, NULL);
	printf("%ld %d is eating.\n", current_time.tv_sec, num);
    if (usleep(s))
	{
		perror("usleep ");
		return (1);
	}
	return (0);
}

void    *routine(void *element)
{
	t_philo *philo;
	philo = (t_philo *)element;
    // print_list(philo, 1);
	while (1)
	{
		thinking(philo->current_time, *philo->num);
		eating(philo->current_time, philo->time_to_eat, *philo->num);
		sleeping(philo->current_time, philo->time_to_sleep, *philo->num);
	}
	return (NULL);
}