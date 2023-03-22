/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:54:13 by achansar          #+#    #+#             */
/*   Updated: 2023/03/22 15:51:26 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
MALLOC
1 struct data
1 pour chque struct philo
1 tableau d'int
1 tableau de mutex
*/

// ./philo 3 6000000 5000000 3000000
/*
etape 1 : parsing
etape 2 : 
etape 3 :
etape 4 : cas d'erreur*/

int	parser(int argc, char **av)
{
	int i;
	
	if (argc != 5 && argc != 6)
	{
		printf("Please enter right number of arguments.\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (ft_isalldigit(av[i++]))
		{
			printf("Please only enter digits.\n");
			return (1);
		}
	}
	return (0);
}

// 100 800 200 200 => failed

int main(int argc, char **argv)
{
	t_data			*data;

	(void)argc;
	(void)argv;
	if (parser(argc, argv) == 0)
	{
		data = init_philo(argv);
		// print_list(data->philo_lst, 2);
		if (monitoring(data, data->philo_lst))
		{
			detach_threads(data->threads, data->philo_lst, data->n_philo);
			destroy_mutexes(data->mutex, data->n_philo);
			pthread_mutex_destroy(&data->mutex_print);
			return (0);
		}
		join_threads(data->threads, data->n_philo);
		return (0);
	}
	return (1);
}
