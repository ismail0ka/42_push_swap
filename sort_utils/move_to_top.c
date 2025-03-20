/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 06:42:41 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/18 08:00:35 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top(t_stack *s, int x)
{
	int	i;

	i = 0;
	if (s->size == 0 || *s->sp == x)
		return ;
	if (s->size >= 2 && s->bp[s->size - 2] == x)
		return (sx(s));
	if (s->bp[i] == x)
		return (rrx(s));
	while (++i < s->size)
	{
		if (s->bp[i] == x)
			break ;
	}
	if (i < s->size / 2)
	{
		while (*s->sp != x)
			rrx(s);
	}
	else
	{
		while (*s->sp != x)
			rx(s);
	}
}
