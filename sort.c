/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:16:08 by ikarouat          #+#    #+#             */
/*   Updated: 2025/02/05 14:34:10 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition(t_stack *a, t_stack *b, int pivot)
{
	int	i;
	int	size;

	i = 0;
	size = a->size;
	while (i < size)
	{
		if (a->elm[a->size - 1] <= pivot)
			pb(b, a);
		else
			ra(a);
		i++;
	}
}

static	int	choose_pivot(t_stack *a)
{
	int		pivot;
	int		i;

	i = 0;
	pivot = a->elm[0];
	while (i < a->size)
	{
		if (a->elm[i] > pivot)
			pivot = a->elm[i];
		i++;
	}
	return (pivot);
}
static int	is_sorted(t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
	if (b->size)
		return (0);
	while (i < a->size - 1)
	{
		if (a->elm[i] > a->elm[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort(t_stack *a, t_stack *b)
{
	int		pivot;

	if (is_sorted(a, b))
		return ;
	pivot = choose_pivot(a);
	partition(a, b, pivot);
	sort(a, b);
	sort(b, a);
	while (b->size)
		pa(a, b);
}