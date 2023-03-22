/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:54:32 by achansar          #+#    #+#             */
/*   Updated: 2023/03/22 15:15:41 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include "libft.h"

t_data          *init_philo(char **av);
pthread_mutex_t *create_mutexes(int nb);

void            *routine(void *element);
pthread_t	    *create_threads(t_philo *philo, int nb);
void            join_threads(pthread_t *t, int nb);
void	        destroy_mutexes(pthread_mutex_t *mutex, int nb);
int	monitoring(t_data *data, t_philo *philo);
int	detach_threads(pthread_t *t, t_philo *p, int nb);

void	print_routine(t_philo *philo, char *str);
#endif
