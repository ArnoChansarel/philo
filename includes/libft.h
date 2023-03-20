/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:42:17 by achansar          #+#    #+#             */
/*   Updated: 2023/03/20 18:21:25 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

typedef struct s_philo {
	int             *num;
	int             *time_to_die;
	int             *time_to_eat;
	int             *time_to_sleep;
	int             *times_eat;
	struct timeval  *last_meal;
	pthread_mutex_t *mutex;
	struct s_philo  *next;
}   t_philo;

typedef struct s_data {
	int     n_philo;
	int     time_to_die;
	int     time_to_eat;
	int     time_to_sleep;
	int    	times_eat;
	pthread_mutex_t	*mutex;
	t_philo			*philo_lst;
	pthread_t		*threads;
}   t_data;

t_philo     *ft_lstlast(t_philo *lst);
void	    ft_lstclear(t_philo **lst);
void	    ft_lstadd_back(t_philo **lst, t_philo *new);
int	        ft_lstsize(t_philo *lst);
t_philo	*ft_lstnew(int *content, t_data *data, pthread_mutex_t *m);
int	        ft_atoi(const char *str);

// DISPLAY
void	print_list(t_philo *philo, int nb);

#endif
