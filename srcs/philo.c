/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:54:13 by achansar          #+#    #+#             */
/*   Updated: 2023/03/17 17:49:44 by achansar         ###   ########.fr       */
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

t_philo *create_loop_list(int nb, t_philo *philo, char **argv)
{
	int     i;
	int		*array;
	t_philo *head;

	i = 1;
	array = malloc(sizeof(int) * nb);
	while (i <= nb)
	{
		array[i - 1] = i;
		ft_lstadd_back(&philo, ft_lstnew(&array[i - 1], argv));
		i++;
	}
	head = ft_lstlast(philo);
	head->next = philo;
	return (philo);
}

// ./philo 3 6000000 1000000 3000000

int main(int argc, char **argv)
{
	int		pnb = 3;
	pthread_t   t[pnb];
	t_philo     *philo = NULL;

	(void)argc;
	(void)argv;
	// init_philo(&philo, 0);
	philo = create_loop_list(pnb, philo, argv);
	// print_list(philo, 1);
	int i = 0;
	if (argc == 5 || argc == 6)
	{
		while(i < pnb)
		{
			if (pthread_create(&t[i], NULL, &routine, (void *)philo) != 0)
			{
				perror("pthread_create ");
				exit(EXIT_FAILURE);
			}
			philo = philo->next;
			i++;
		}
		i = 0;
		while (i < pnb)
		{
			if (pthread_join(t[i], NULL) != 0)
			{
				perror("pthread_join ");
				exit(EXIT_FAILURE);
			}
			i++;
		}
		return (0);
	}
	return (1);
}
