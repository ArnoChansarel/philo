/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:34:35 by achansar          #+#    #+#             */
/*   Updated: 2023/03/28 18:15:03 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

pthread_mutex_t	*create_mutexes(int nb)
{
	int				i;
	pthread_mutex_t	*mutex;

	mutex = malloc(sizeof(pthread_mutex_t) * nb);
	if (!mutex)
		return (mutex);
	i = 0;
	while (i < nb)
	{
		if (pthread_mutex_init(&mutex[i++], NULL))
		{
			mutex = NULL;
			free(mutex);
			break ;
		}
	}	
	return (mutex);
}

int	destroy_mutexes(pthread_mutex_t *mutex, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (pthread_mutex_destroy(&mutex[i++]))
		{
			mutex = NULL;
			free(mutex);
			return (1);
		}
	}
	return (0);
}

pthread_t	*create_threads(t_philo *philo, int nb)
{
	int			i;
	pthread_t	*t;
	t_philo		*head;

	head = philo;
	t = malloc(sizeof(pthread_t) * nb);
	if (!t)
		return (t);
	i = 0;
	while (i < nb)
	{
		if (*philo->num % 2)
			usleep(50);
		if (pthread_create(&t[i++], NULL, &routine, (void *)head) != 0)
		{
			printf("Error : pthread_create\n");
			t = NULL;
			free(t);
			return (t);
		}
		head = head->next;
	}
	return (t);
}

int	join_threads(pthread_t *t, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (pthread_join(t[i++], NULL) != 0)
		{
			printf("Error : pthread_join.\n");
			return (1);
		}
	}
	return (0);
}
