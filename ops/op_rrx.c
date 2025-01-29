/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:37:49 by ikarouat          #+#    #+#             */
/*   Updated: 2025/01/29 13:54:51 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->size < 2)
		return ;
	i = stack->size - 1;
	tmp = stack->elm[stack->size - 1];
	while (i > 0)
	{
		stack->elm[i] = stack->elm[i - 1];
		i--;
	}
	stack->elm[0] = tmp;
}

void	rra(t_stack *a)
{
	rrx(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	rrx(b);
	ft_printf("rrb\n");
}