/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:43:49 by achansar          #+#    #+#             */
/*   Updated: 2023/03/22 15:40:30 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_philo *create_loop_list(t_data *data, t_philo *philo, pthread_mutex_t *m)
{
	int     i;
	int		*array;
	t_philo *head;

	i = 1;
	array = malloc(sizeof(int) * data->n_philo);
	while (i <= data->n_philo)
	{
		array[i - 1] = i;
		ft_lstadd_back(&philo, ft_lstnew(&array[i - 1], data, &m[i - 1]));
		i++;
	}
	head = ft_lstlast(philo);
	head->next = philo;
	return (philo);
}

int	create_elements(t_data *data)
{
	t_philo *philo;
	pthread_mutex_t	p;
	
	philo = NULL;
	pthread_mutex_init(&p, NULL);
	data->mutex_print = p;
    data->mutex = create_mutexes(data->n_philo);
    data->philo_lst = create_loop_list(data, philo, data->mutex);//         PROTECT
	if (data->n_philo == 1)
	{
		print_routine(data->philo_lst, "died.");
		exit(EXIT_FAILURE);
	}
    data->threads = create_threads(data->philo_lst, data->n_philo);
	return (0);
}

t_data *init_philo(char **av)
{
    t_data *data;
    
    data = NULL;
    data = malloc(sizeof(t_data));
    if (!data)
        return (data);
    data->n_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);

	data->time_to_eat = ft_atoi(av[3]);
	
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->times_eat = ft_atoi(av[5]);
	else
		data->times_eat = 0;
	data->start = get_time_mili();
	if (create_elements(data))
		return (data);
    return (data);
}
