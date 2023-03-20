/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:54:32 by achansar          #+#    #+#             */
/*   Updated: 2023/03/20 18:21:10 by achansar         ###   ########.fr       */
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

void	print_routine(int num, char *str);
#endif
