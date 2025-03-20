/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_empty_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:35:19 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/16 21:38:15 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(const char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static int	is_empty(const char *s)
{
	while (is_space(*s))
		s++;
	if (*s == 0)
		return (1);
	return (0);
}

int	has_empty_str(const char **args)
{
	int	i;

	i = -1;
	while (args && args[++i])
	{
		if (is_empty(args[i]))
			return (1);
	}
	return (0);
}
