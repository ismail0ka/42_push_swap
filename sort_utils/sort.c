/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:16:08 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/18 16:45:33 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*init_range(t_stack *a, t_range *range)
{
	int	i;
	int	n;
	int	*tab;
	int	chunk_size;

	chunk_size = 1;
	if (a->size <= 100)
		chunk_size = a->size / 8;
	else
		chunk_size = a->size / 18;
	tab = malloc(a->size * sizeof(int));
	if (!tab)
		(write(2, "Error\n", 6), exit(1));
	i = -1;
	while (++i < a->size)
		tab[i] = a->bp[i];
	n = a->size - 1;
	quick_sort(tab, 0, n);
	range->mid = (n / 2);
	range->offset = chunk_size;
	if (range->offset == 0)
		range->offset = 1;
	range->begin = range->mid - range->offset;
	range->end = range->mid + range->offset;
	return (tab);
}

static int	has_num_in_range(t_stack *a, int *tab, t_range *range, int *index)
{
	int	i;
	int	min_moves;
	int	moves;
	int	chosen_index;

	min_moves = a->size;
	chosen_index = -1;
	i = -1;
	while (++i < a->size)
	{
		if (a->bp[i] >= tab[range->begin] && a->bp[i] <= tab[range->end])
		{
			if (i <= a->size / 2)
				moves = i;
			else
				moves = a->size - 1 - i;
			if (moves < min_moves)
			{
				min_moves = moves;
				chosen_index = i;
			}
		}
	}
	return (*index = chosen_index, chosen_index != -1);
}

static void	push_to_b(t_stack *a, t_stack *b, int *tab, t_range *range)
{
	int	n;
	int	in_range_index;

	n = a->size - 1;
	in_range_index = 0;
	while (a->size)
	{
		while (has_num_in_range(a, tab, range, &in_range_index))
		{
			move_to_top(a, a->bp[in_range_index]);
			if (*a->sp > tab[range->mid])
				pb(a, b);
			else
				(pb(a, b), rx(b));
		}
		range->begin -= range->offset;
		range->end += range->offset;
		if (range->begin < 0)
			range->begin = 0;
		if (range->end > n)
			range->end = n;
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b, int *tab)
{
	int	not_sorted;
	int	i;

	i = b->size - 1;
	not_sorted = 0;
	while (b->size)
	{
		not_sorted = !is_sorted(a);
		if (!max_is_on_b(b, tab[i]))
			(rrx(a), i--);
		else if (*b->sp == tab[i])
			(pa(a, b), i--);
		else if (a->size && (not_sorted == 0 || *b->sp > a->bp[0]))
		{
			pa(a, b);
			rx(a);
		}
		else
			move_to_top(b, b->bp[get_max(b)]);
	}
	while (!is_sorted(a))
		rrx(a);
}

void	sort(t_stack *a, t_stack *b)
{
	int		*tab;
	t_range	*range;

	range = malloc(sizeof(t_range));
	tab = init_range(a, range);
	push_to_b(a, b, tab, range);
	push_back_to_a(a, b, tab);
	(free(tab), free(range));
}
//->[x0, x1, x2, x9 , x4, x7, x6, x5, x3, x8]a
//---__--__-------------------------------__
//->[]b