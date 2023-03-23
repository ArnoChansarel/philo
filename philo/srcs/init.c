/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:43:49 by achansar          #+#    #+#             */
/*   Updated: 2023/03/23 11:27:55 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_philo	*create_loop_list(t_data *data, t_philo *ph, pthread_mutex_t *m)
{
	int		i;
	int		*array;
	t_philo	*head;

	i = 1;
	array = malloc(sizeof(int) * data->n_philo);
	if (!array)
	{
		*ph->num = -1;
		return (ph);
	}
	while (i <= data->n_philo)
	{
		array[i - 1] = i;
		ft_lstadd_back(&ph, ft_lstnew(&array[i - 1], data, &m[i - 1]));
		i++;
	}
	head = ft_lstlast(ph);
	head->next = ph;
	return (ph);
}

t_data	*create_elements(t_data *data)
{
	t_philo			*philo;
	pthread_mutex_t	p;

	philo = NULL;
	pthread_mutex_init(&p, NULL);
	data->mutex_print = p;
	data->mutex = create_mutexes(data->n_philo);
	if (!data->mutex)
	{
		data = free_and_destroy(data);
		return (data);
	}
	data->philo_lst = create_loop_list(data, philo, data->mutex);
	if (*data->philo_lst->num == -1)
	{
		data = free_and_destroy(data);
		return (data);
	}
	data->threads = create_threads(data->philo_lst, data->n_philo);
	if (data->threads)
	{
		data = free_and_destroy(data);
		return (data);
	}
	return (0);
}

int	check_atoi(t_data *data, char **av)
{
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->times_eat = ft_atoi(av[5]);
	else
		data->times_eat = 0;
	if (data->time_to_die == 0 || data->time_to_eat == 0
		|| data->time_to_sleep == 0)
		return (1);
	return (0);
}

t_data	*free_and_return(t_data *data, char *str)
{
	printf("%s", str);
	data = NULL;
	free(data);
	return (data);
}

t_data	*init_philo(char **av)
{
	t_data	*data;

	data = NULL;
	data = malloc(sizeof(t_data));
	if (!data)
		return (data);
	memset(data, '\0', sizeof(t_data));
	data->n_philo = ft_atoi(av[1]);
	if (data->n_philo == 0 || data->n_philo >= 1024)
		return (free_and_return(data, "Wrong number of philosophers.\n"));
	if (check_atoi(data, av))
		return (free_and_return(data, "Wrong arguments.\n"));
	data->start = get_time_mili();
	create_elements(data);
	if (!data)
	{
		printf("Issue allocating one of the elements.\n");
		return (data);
	}
	return (data);
}
