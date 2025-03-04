/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:33:15 by ikarouat          #+#    #+#             */
/*   Updated: 2024/10/31 22:39:14 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	clean_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	unsigned char	first;
	int				res;
	int				spaces;

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
