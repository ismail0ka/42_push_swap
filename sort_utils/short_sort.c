/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 23:19:00 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/07 01:31:26 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_to_top(t_stack *a, int x)
{
	int	i;

	i = 0;
	if (a->bp[i] == x)
		return (rra(a));
	while (++i < a->size)
	{
		if (a->bp[i] == x)
			break ;
	}
	if (i <= a->size / 2)
	{
		while (*a->sp != x)
			rra(a);
	}
	else
	{
		while (*a->sp != x)
			ra(a);
	}
}

static void	sort_two(t_stack *a)
{
	if (*(a->sp) > *(a->bp))
		ra(a);
}

static void	sort_three(t_stack *a)
{
	int x0 = *(a->sp);
    int x1 = a->bp[1];
    int x2 = a->bp[0];

    if (x0 > x1 && x1 < x2 && x2 > x0)
        sa(a);
    else if (x0 > x1 && x1 > x2)
        (sa(a), rra(a));
    else if (x0 > x1 && x1 < x2 && x2 < x0)
        ra(a);
    else if (x0 < x1 && x1 > x2 && x2 > x0)
    	(sa(a), ra(a));
    else if (x0 < x1 && x1 > x2 && x2 < x0)
        rra(a);
}

static void	sort_four(t_stack *a, t_stack *b)
{
	int	min;
	int	i;

	i = get_min(a);
	min = a->bp[i];
	if (min == *a->bp)
		pb(a, b);
	else
	{
		move_to_top(a, min);
		pb(a, b);
	}
	sort_three(a);
	pa(a, b);
}

static void	sort_five(t_stack *a, t_stack *b)
{
	int	min;
	int	i;

	i = get_min(a);
	min = a->bp[i];
	if (min == *a->bp)
		pb(a, b);
	else
	{
		move_to_top(a, min);
		pb(a, b);
	}
	sort_four(a, b);
	pa(a, b);
}

void	short_sort(t_stack *a, t_stack *b)
{
	if (a->size == 1)
		return ;
	else if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else
		sort_five(a, b);
}
