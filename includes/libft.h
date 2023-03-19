/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:42:17 by achansar          #+#    #+#             */
/*   Updated: 2023/03/19 17:36:49 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <pthread.h>
    
typedef struct s_philo {
    int             *num;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             times_eat;
    struct timeval  current_time;
    int             is_alive;
    pthread_mutex_t *mutex;
    struct s_philo  *next;
}   t_philo;

t_philo     *ft_lstlast(t_philo *lst);
void	    ft_lstclear(t_philo **lst);
void	    ft_lstadd_back(t_philo **lst, t_philo *new);
int	        ft_lstsize(t_philo *lst);
t_philo	*ft_lstnew(int *content, char **av, pthread_mutex_t *m);
int	        ft_atoi(const char *str);

// DISPLAY
void	print_list(t_philo *philo, int nb);

#endif
