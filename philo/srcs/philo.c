/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:54:13 by achansar          #+#    #+#             */
/*   Updated: 2023/03/28 18:31:23 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (parser(argc, argv) == 0)
	{
		data = init_philo(argv);
		if (!data)
			return (1);
		if (monitoring(data, data->philo_lst))
			unlock_all(data);
		if (join_threads(data->threads, data->n_philo))
		{
			free_and_destroy(data);
			return (1);
		}
		free_and_destroy(data);
		return (0);
	}
	return (1);
}
