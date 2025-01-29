/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:10:31 by ikarouat          #+#    #+#             */
/*   Updated: 2025/01/29 13:26:46 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->size < 2)
		return ;
	i = 0;
	tmp = stack->elm[0];
	while (i < stack->size - 1)
	{
		stack->elm[i] = stack->elm[i + 1];
		i++;
	}
	stack->elm[stack->size - 1] = tmp;
}

void	ra(t_stack *a)
{
	rx(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	rx(b);
	ft_printf("rb\n");
}