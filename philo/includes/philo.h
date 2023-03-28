/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:54:32 by achansar          #+#    #+#             */
/*   Updated: 2023/03/28 18:23:54 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "libft.h"

t_data			*init_philo(char **av);
pthread_mutex_t	*create_mutexes(int nb);
int				parser(int argc, char **av);
void			*routine(void *element);
pthread_t		*create_threads(t_philo *philo, int nb);
int				join_threads(pthread_t *t, int nb);
int				destroy_mutexes(pthread_mutex_t *mutex, int nb);
int				monitoring(t_data *data, t_philo *philo);
void			unlock_all(t_data *data);

#endif
