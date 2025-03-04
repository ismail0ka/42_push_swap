/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:08:22 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/03 05:39:46 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int size)
{
	t_stack	*stack;

	if (size == 0)
		return (NULL);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->bp = (int *)malloc(sizeof(int) * size);
	if (!stack->bp)
	{
		free(stack);
		return (NULL);
	}
	stack->sp = stack->bp;
	stack->size = size;
	return (stack);
}