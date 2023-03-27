/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:54:13 by achansar          #+#    #+#             */
/*   Updated: 2023/03/27 17:11:40 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parser(int argc, char **av)
{
	int	i;

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

t_data	*free_and_destroy(t_data *data)
{
	if (data->mutex_print)
	{
		// printf("CRASH ?\n");
		free(data->mutex_print);
		// printf(" CRASH PAS ?\n");
	}
	if (data->mutex)
	{
		destroy_mutexes(data->mutex, data->n_philo);
		free(data->mutex);
	}
	if (data->philo_lst)
	{
		if (data->philo_lst->num)
			free(data->philo_lst->num);
		ft_lstclear(&data->philo_lst, data->n_philo);
	}
	if (data->threads)
	{
		free(data->threads);
	}
	data = NULL;
	free(data);
	return (data);
}


/*
5 800 200 200 7 => segfault ?
4 410 200 200 10 => segfault ? 10 meals ?
200 800 200 200 => 2 sec ???

NO DIE
5 600 150 150
4 410 200 200
100 800 200 200
105 800 200 200
*/
int	main(int argc, char **argv)
{
	t_data	*data;

	if (parser(argc, argv) == 0)
	{
		data = init_philo(argv);
		if (!data)
			return (1);
		monitoring(data, data->philo_lst);
			// pthread_mutex_unlock(data->mutex_print);
		join_threads(data->threads, data->n_philo);
			if (pthread_mutex_destroy(data->mutex_print))//      Unknown error
			{
				printf("crame\n");
				free_and_destroy(data);
				return (1);
			}
			free_and_destroy(data);
			return (0);
	}
	return (1);
}
