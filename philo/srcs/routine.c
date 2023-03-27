/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:45:21 by achansar          #+#    #+#             */
/*   Updated: 2023/03/27 17:24:35 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_routine(t_philo *philo, char *str)
{
	long	time;

	time = get_time_mili();
	pthread_mutex_lock(philo->print);
	if (*philo->death == 0)
		printf("%ld %d %s\n", time - *philo->start, *philo->num, str);
	pthread_mutex_unlock(philo->print);
}

static int	usleep_custom(t_philo *philo, long time_to)
{
	long	start;
	long	now;

	start = get_time_mili();
	while (*philo->death == 0)
	{
		now = get_time_mili();
		if (now - start >= time_to)
			break ;
		if (usleep(100))
			return (1);
	}
	return (0);
}

static int	sleeping(t_philo *philo)
{
	print_routine(philo, "is sleeping.");
	if (usleep_custom(philo, *philo->time_to_sleep))
		return (1);
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
	if (usleep_custom(philo, *philo->time_to_eat))
		return (1);
	pthread_mutex_unlock(philo->mutex);
	pthread_mutex_unlock(philo->next->mutex);
	return (0);
}

void	*routine(void *element)
{
	t_philo	*philo;

	philo = (t_philo *)element;
	if (*philo->num == *philo->next->num)
	{
		print_routine(philo, "died.");
		*philo->death = 1;
		return (NULL);
	}
	while (*philo->death == 0)
	{
		print_routine(philo, "is thinking.");
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}
