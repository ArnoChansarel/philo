/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:35:48 by achansar          #+#    #+#             */
/*   Updated: 2023/03/17 17:50:12 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*number_of_philosophers time_to_die time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]*/

t_philo	*ft_lstnew(int *content, char **av)
{
	t_philo	*ele;
	
	ele = NULL;
	ele = malloc(sizeof(t_philo));
	if (!ele)
		return (NULL);
	ele->num = content;
	ele->time_to_die = ft_atoi(av[2]);
	ele->time_to_eat = ft_atoi(av[3]);
	ele->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		ele->times_eat = ft_atoi(av[5]);
	else
		ele->times_eat = 0;
    ele->fork = 1;
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

void	ft_lstclear(t_philo **lst)
{
	t_philo	*tmp;

	if (!lst)
		return ;
	tmp = NULL;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
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
