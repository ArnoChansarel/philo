/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:41:56 by achansar          #+#    #+#             */
/*   Updated: 2023/03/17 17:42:45 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_isdigit(int c)
{
	if ((c < '0') || (c > '9'))
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	long long	nb;
	long		sign;
	int			i;
	long		save;

	nb = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]))
	{
		save = nb;
		nb = nb * 10 + str[i++] - '0';
		if (nb - (sign == -1) < save)
			return (256);
	}
	return ((int)(nb * sign));
}