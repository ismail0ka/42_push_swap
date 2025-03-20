/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 03:56:20 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/19 04:09:28 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	clean_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

long	ft_atol(const char *str)
{
	unsigned char	first;
	long			res;
	long			spaces;

	spaces = clean_spaces(str);
	first = str[spaces++];
	res = 0;
	if (first == '-' || first == '+' || ft_isdigit(first))
	{
		if (ft_isdigit(first))
			res = first - 48;
		while ((unsigned long) spaces < ft_strlen(str))
		{
			if (ft_isdigit(str[spaces]))
				res = res * 10 + (str[spaces] - 48);
			else
				break ;
			spaces++;
		}
		if (first == '-')
			res *= -1;
		return (res);
	}
	return (0);
}
