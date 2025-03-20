/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:37:49 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/07 06:59:21 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx(t_stack *stack)
{
	int	i;
	int	to_top;

	if (stack->size < 2)
		return ;
	i = 0;
	to_top = stack->bp[0];
	while (i < stack->size - 1)
	{
		stack->bp[i] = stack->bp[i + 1];
		i++;
	}
	stack->bp[stack->size - 1] = to_top;
	if (stack->size >= 2)
	{
		if (stack->name == 'a')
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
	}
}

/*void	rra(t_stack *a)
{
	rrx(a);
	if (a->size >= 2)
		ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	rrx(b);
	if (b->size >= 2)
		ft_printf("rrb\n");
}*/