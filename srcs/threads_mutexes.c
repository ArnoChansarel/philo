/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:34:35 by achansar          #+#    #+#             */
/*   Updated: 2023/03/20 17:14:08 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

pthread_mutex_t	*create_mutexes(int nb)
{
	int 			i;
	pthread_mutex_t *mutex;

	mutex = malloc(sizeof(pthread_mutex_t) * nb);
	if (!mutex)
		return (mutex);
	i = 0;
	while (i < nb)
		pthread_mutex_init(&mutex[i++], NULL);
	return (mutex);
}

void	destroy_mutexes(pthread_mutex_t *mutex, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&mutex[i]);
		i++;
	}
}

pthread_t	*create_threads(t_philo *philo, int nb)
{
	int 		i;
	pthread_t	*t;
    t_philo     *head;

    head = philo;
	t = malloc(sizeof(pthread_t) * nb);
	if (!t)
		return (t);
	i = 0;
	while (i < nb)
	{
        if (pthread_create(&t[i++], NULL, &routine, (void *)head) != 0)
		{
			perror("pthread_create ");
			exit(EXIT_FAILURE);
		}
		head = head->next;
	}
	return (t);
}

void    join_threads(pthread_t *t, int nb)
{
    int i;
    
	i = 0;
	while (i < nb)
	{
		if (pthread_join(t[i++], NULL) != 0)
		{
			perror("pthread_join ");
			exit(EXIT_FAILURE);
		}
	}
}