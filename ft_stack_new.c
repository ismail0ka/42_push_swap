/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:08:22 by ikarouat          #+#    #+#             */
/*   Updated: 2025/01/28 21:08:44 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->elm = (int *)malloc(sizeof(int) * size);
	if (!stack->elm)
	{
		free(stack);
		return (NULL);
	}
	stack->sp = stack->elm;
	stack->size = size;
	return (stack);
}