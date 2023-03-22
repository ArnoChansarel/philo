/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:01:12 by achansar          #+#    #+#             */
/*   Updated: 2023/03/22 15:50:35 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	int i;

	i = 0;
	while (i < nb)
	{
		pthread_detach(t[i]);
		p = p->next;
		i++;
	}
	return (0);
}

void	print_list(t_philo *philo, int nb)
{
	int i = 1;//                                =>creer tableau d'index
	t_philo *head = philo;

	while (i <= nb * 2)
	{
		printf("philo numero %d\n", *head->num);
		printf("time sleep = %d\n", *head->time_to_sleep);
		head = head->next;
		i++;
	}
}

static int	check_all_meals(int nb, t_philo *philo)
{
	int i;

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
	while (head)
	{
		time = get_time_mili();
		if (time >= head->last_meal + *philo->time_to_die)
		{
			// printf("check death\n");
			// printf("time to die = %d\n", *philo->time_to_die);
			// printf("%ld - %ld = %ld\n", time, head->last_meal, time - head->last_meal);
			// printf("timetodie + last meal = %ld\n", *philo->time_to_die + philo->last_meal);
			print_routine(philo, "died.");
			pthread_mutex_lock(&data->mutex_print);
			return (1);
		}
		if (data->times_eat)
		{
			if (check_all_meals(data->n_philo, philo))
			{
				pthread_mutex_lock(&data->mutex_print);
				return(1);
			}	
		}
		head = head->next;
	}
	return (0);
}
