/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_px.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:54:26 by ikarouat          #+#    #+#             */
/*   Updated: 2025/01/28 22:08:35 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(t_stack *to, t_stack *from)
{
	if (from->size == 0)
		return ;
	to->elm[to->size - 1] = from->elm[from->size - 1];
	to->size++;
	from->size--;
	to->sp = &to->elm[to->size - 1];
	from->sp = &from->elm[from->size - 1];
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