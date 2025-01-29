/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:51:35 by ikarouat          #+#    #+#             */
/*   Updated: 2025/01/28 22:00:31 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->elm[stack->size - 1];
	stack->elm[stack->size - 1] = stack->elm[stack->size - 2];
	stack->elm[stack->size - 2] = tmp;
}

void	sa(t_stack *stack)
{
	sx(stack);
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	sx(stack);
	ft_printf("sb\n");
}
