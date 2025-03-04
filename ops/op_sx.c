/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:51:35 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/02 06:10:02 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->bp[stack->size - 1];
	stack->bp[stack->size - 1] = stack->bp[stack->size - 2];
	stack->bp[stack->size - 2] = tmp;
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
