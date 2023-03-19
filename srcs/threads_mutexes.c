/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:34:35 by achansar          #+#    #+#             */
/*   Updated: 2023/03/19 16:37:49 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

pthread_mutex_t	*create_mutexes(int nb)
{
	int 			i;
	pthread_mutex_t *mutex;
	
	mutex = NULL;
	mutex = malloc(sizeof(pthread_mutex_t *) * nb);
	if (!mutex)
		return (mutex);
	i = 0;
	while (i < nb)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
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

// pthread_t	*create_threads(int nb)
// {
// 	int 		i;
// 	pthread_t	*t;
	
// 	t = NULL;
// 	t = malloc(sizeof(pthread_t *) * nb);
// 	if (!t)
// 		return (t);
// 	i = 0;
// 	while (i < nb)
// 	{
// 		i++;
// 	}
// 	return (t);
// }

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