/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:54:13 by achansar          #+#    #+#             */
/*   Updated: 2023/03/23 10:48:28 by achansar         ###   ########.fr       */
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

void	*free_and_destroy(t_data *data)
{
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
		free(data->threads);
	free(data);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (parser(argc, argv) == 0)
	{
		data = init_philo(argv);
		if (!data)
			return (1);
		if (data->n_philo == 1)
		{
			print_routine(data->philo_lst, "died.");
			data = free_and_destroy(data);
			return (0);
		}
		if (monitoring(data, data->philo_lst))
		{
			detach_threads(data->threads, data->philo_lst, data->n_philo);
			pthread_mutex_destroy(&data->mutex_print);
			free_and_destroy(data);
			return (0);
		}
		join_threads(data->threads, data->n_philo);
		return (0);
	}
	return (1);
}
