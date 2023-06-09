/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:35:48 by achansar          #+#    #+#             */
/*   Updated: 2023/03/23 19:29:59 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_philo	*ft_lstnew(int *content, t_data *data, pthread_mutex_t *m)
{
	t_philo	*ele;

	ele = NULL;
	ele = malloc(sizeof(t_philo));
	if (!ele)
		return (NULL);
	ele->num = content;
	ele->time_to_die = &data->time_to_die;
	ele->time_to_eat = &data->time_to_eat;
	ele->time_to_sleep = &data->time_to_sleep;
	ele->times_eat = &data->times_eat;
	ele->mutex = m;
	ele->meal = 0;
	ele->last_meal = get_time_mili();
	ele->print = data->mutex_print;
	ele->start = &data->start;
	ele->death = &data->death;
	ele->next = NULL;
	return (ele);
}

int	ft_lstsize(t_philo *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*last;

	if (!lst || !new)
		return ;
	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

int	ft_lstclear(t_philo **lst, int nb)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	if (!lst)
		return (1);
	tmp = NULL;
	while (*lst && i < nb)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
		i++;
	}
	return (1);
}

t_philo	*ft_lstlast(t_philo *lst)
{
	int	s;
	int	i;

	if (!lst)
		return (0);
	i = 0;
	s = ft_lstsize(lst);
	while (lst && i < s - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
