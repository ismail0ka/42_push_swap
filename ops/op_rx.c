/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:10:31 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/02 06:09:55 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(t_stack *stack)
{
	int	i;
	int	to_bottom;

	if (stack->size < 2)
		return ;
	i = stack->size - 1;
	to_bottom = *(stack->sp);
	while (i > 0)
	{
		stack->bp[i] = stack->bp[i - 1];
		i--;
	}
	stack->bp[0] = to_bottom;
}

void	ra(t_stack *a)
{
	rx(a);
	if (a->size >= 2)
		ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	rx(b);
	if (b->size >= 2)
		ft_printf("rb\n");
}