/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:01:12 by achansar          #+#    #+#             */
/*   Updated: 2023/03/28 18:23:37 by achansar         ###   ########.fr       */
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

static int	check_all_meals(int nb, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (philo->meal < *philo->times_eat)
			return (0);
		i++;
		philo = philo->next;
	}
	*philo->death = 1;
	return (1);
}

void	unlock_all(t_data *data)
{
	int		i;
	t_philo	*head;

	i = 0;
	head = data->philo_lst;
	while (i++ < data->n_philo)
	{
		pthread_mutex_unlock(head->mutex);
		head = head->next;
	}
}

int	monitoring(t_data *data, t_philo *philo)
{
	t_philo	*head;
	long	time;

	head = philo;
	while (head)
	{
		usleep(100);
		time = get_time_mili();
		if ((time - *philo->start) - (head->last_meal - *philo->start)
			> *philo->time_to_die)
		{
			print_routine(philo, "died.");
			data->death = 1;
			return (1);
		}
		if (data->times_eat)
		{
			if (check_all_meals(data->n_philo, philo))
				return (1);
		}
		head = head->next;
	}
	return (0);
}
