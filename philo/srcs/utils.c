/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:01:12 by achansar          #+#    #+#             */
/*   Updated: 2023/03/23 20:05:58 by achansar         ###   ########.fr       */
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

int	ft_isalldigit(char *str)
{
	while (*str)
	{
		if (*str < 48 || *str > 57)
			return (1);
		str++;
	}
	return (0);
}

int	detach_threads(pthread_t *t, t_philo *p, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		pthread_detach(t[i]);
		p = p->next;
		i++;
	}
	return (0);
}

static int	check_all_meals(int nb, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (philo->meal < *philo->times_eat)
		{
			return (0);
		}
		i++;
		philo = philo->next;
	}
	return (1);
}

int	monitoring(t_data *data, t_philo *philo)
{
	t_philo	*head;
	long	time;

	head = philo;
	while (head && data->death == 0)
	{
		time = get_time_mili();
		if (time >= head->last_meal + *philo->time_to_die)
		{
			data->death = 1;
			// pthread_mutex_lock(data->mutex_print);
			print_routine(philo, "died.");
			return (1);
		}
		if (data->times_eat)
		{
			if (check_all_meals(data->n_philo, philo))
			{
				pthread_mutex_lock(data->mutex_print);
				return (1);
			}	
		}
		head = head->next;
	}
	return (0);
}
