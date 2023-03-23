/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:42:17 by achansar          #+#    #+#             */
/*   Updated: 2023/03/23 19:26:06 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <stdatomic.h>

typedef struct s_philo {
	int				*num;
	int				*time_to_die;
	int				*time_to_eat;
	int				*time_to_sleep;
	int				*times_eat;
	_Atomic int		meal;
	_Atomic long	last_meal;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*print;
	struct s_philo	*next;
	long			*start;
	_Atomic int		*death;
}	t_philo;

typedef struct s_data {
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_eat;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*mutex_print;
	t_philo			*philo_lst;
	pthread_t		*threads;
	_Atomic int		death;
	long			start;
}	t_data;

t_philo		*ft_lstlast(t_philo *lst);
int			ft_lstclear(t_philo **lst, int nb);
void		ft_lstadd_back(t_philo **lst, t_philo *new);
int			ft_lstsize(t_philo *lst);
t_philo		*ft_lstnew(int *content, t_data *data, pthread_mutex_t *m);
int			ft_atoi(const char *str);
int			ft_isalldigit(char *str);

long		get_time_mili(void);
t_data		*free_and_destroy(t_data *data);
void		print_routine(t_philo *philo, char *str);

#endif
