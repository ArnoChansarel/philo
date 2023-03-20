/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:54:13 by achansar          #+#    #+#             */
/*   Updated: 2023/03/20 18:27:24 by achansar         ###   ########.fr       */
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

Si un philo meurt, la simu prend fin.
Si tous ont mange au moins le nombre, simu prend fin
*/

/*
MALLOC
1 struct data
1 pour chque struct philo
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
		printf("time sleep = %d\n", *head->time_to_sleep);
		head = head->next;
		i++;
	}
}



// ./philo 3 6000000 5000000 3000000
/*
etape 1 : 
etape 2 : gestion de la mort
etape 3 : datarace
etape 4 : cas d'erreur*/

int	check_death(t_philo *philo)
{
	t_philo 		*head;
	struct timeval	time;

	head = philo;
	while (head)
	{
		gettimeofday(&time, NULL);
		printf("head = %ld\n", head->last_meal->tv_sec);
		// if (time.tv_sec - head->last_meal->tv_sec /*>= *philo->time_to_die*/)
		// {
		// 	print_routine(*philo->num, "died.");
		// 	return (1);
		// }
		head = head->next;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_data			*data;

	if (argc == 5 || argc == 6)
	{
		data = init_philo(argv);
		while (1)
		{
			if (check_death(data->philo_lst))
			{
				//detach_threads();
				destroy_mutexes(data->mutex, data->n_philo);
				return (0);
			}
		}
		join_threads(data->threads, data->n_philo);
		printf("AFTER_JOIN\n");
		return (0);
	}
	return (1);
}
