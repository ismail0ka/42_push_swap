/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:54:26 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/02 06:09:30 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(t_stack *to, t_stack *from)
{
	if (from->size == 0)
		return ;
	to->bp[to->size - 1] = from->bp[from->size - 1];
	to->size++;
	from->size--;
	to->sp = &to->bp[to->size - 1];
	from->sp = &from->bp[from->size - 1];
}

void	pa(t_stack *a, t_stack *b)
{
	px(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	px(b, a);
	ft_printf("pb\n");
}