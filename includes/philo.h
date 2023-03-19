/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:54:32 by achansar          #+#    #+#             */
/*   Updated: 2023/03/19 17:04:05 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include "libft.h"

void            *routine(void *element);

pthread_mutex_t *create_mutexes(int nb);
void	        destroy_mutexes(pthread_mutex_t *mutex, int nb);


void    join_threads(pthread_t *t, int nb);
#endif
