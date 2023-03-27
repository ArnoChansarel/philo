/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:11:13 by achansar          #+#    #+#             */
/*   Updated: 2023/03/27 18:18:42 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data	*free_and_destroy(t_data *data)
{
	if (data->mutex_print)
	{
		pthread_mutex_destroy(data->mutex_print);
		free(data->mutex_print);
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
		free(data->threads);
	data = NULL;
	free(data);
	return (data);
}

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
