/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:54:13 by achansar          #+#    #+#             */
/*   Updated: 2023/03/19 17:17:32 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*

faire une liste chainee circulaire
fourchette ont etat a 1 ou 0. 
un philosophe utilise sa propre fourchette + fourchette (les deux a 1) du suivant pour manger.

chaque thread comprend un loop avec 3 fonctions inside :
	thinking (by default)
	eating
	sleeping

en entree une structure avec
	- time to die => doit avoir commence a manger apres ce temps
	- time to eat => prend ce temps a manger, bloquant ainsi les fourchettes autour de lui
	- time to sleep
	- (optionnal) nb of time to eat
	- is alive

*/

/*
MALLOC
1 pour chque struct
1 tableau d'int
1 tableau de mutex
*/


void	print_list(t_philo *philo, int nb)
{
	int i = 1;//                                =>creer tableau d'index
	t_philo *head = philo;
	
	while (i <= nb * 2)
	{
		printf("philo numero %d\n", *head->num);
		printf("time sleep = %d\n", head->time_to_sleep);
		head = head->next;
		i++;
	}
}

t_philo *create_loop_list(int nb, t_philo *philo, char **argv, pthread_mutex_t *m)
{
	int     i;
	int		*array;
	t_philo *head;

	i = 1;
	array = malloc(sizeof(int) * nb);
	while (i <= nb)
	{
		array[i - 1] = i;
		ft_lstadd_back(&philo, ft_lstnew(&array[i - 1], argv, &m[i - 1]));
		i++;
	}
	head = ft_lstlast(philo);
	head->next = philo;
	return (philo);
}

// ./philo 3 6000000 5000000 3000000
/*
etape 1 : MUTEX
etape 2 : gestion de la mort
etape 3 : cas d'erreur*/



int main(int argc, char **argv)
{
	int 			i;
	int				pnb = ft_atoi(argv[1]);
	pthread_t   	t[pnb];
	pthread_mutex_t	*mutex = NULL;	
	t_philo     	*philo = NULL;

	i = 0;
	// pnb = ft_atoi(argv[1]);
	// print_list(philo, 1);
	if (argc == 5 || argc == 6)
	{
		mutex = create_mutexes(pnb);
		philo = create_loop_list(pnb, philo, argv, mutex);
		// create_threads();
		while(i < pnb)
		{
			
			if (pthread_create(&t[i++], NULL, &routine, (void *)philo) != 0)
			{
				perror("pthread_create ");
				exit(EXIT_FAILURE);
			}
			philo = philo->next;
		}
		join_threads(t, pnb);
		destroy_mutexes(mutex, pnb);
		return (0);
	}
	return (1);
}
