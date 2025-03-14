/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:16:08 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/14 07:48:44 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a);

static int	*init_range(t_stack *a, t_range *range)
{
	int	i;
	int	n;
	int	*tab;
	int	chunk_size;

	chunk_size = 1;
	if (a->size <= 100)
		chunk_size = a->size / 10;
	else
		chunk_size = a->size / 21;
	tab = malloc(a->size * sizeof(int));
	if (!tab)
		(write(2, "Error\n", 6), exit(1));
	i = -1;
	while (++i < a->size)
		tab[i] = a->bp[i];
	n = a->size - 1;
	quick_sort(tab, 0, n);
	range->mid = n / 2;
	range->offset = (a->size) / chunk_size;
	range->begin = (n / 2) - range->offset;
	range->end = (n / 2) + range->offset;
	return (tab);
}

static int	has_num_in_range(t_stack *a, t_range *range, int *index)
{
	int	n;

	n = a->size - 1;
}

static void	push_to_b(t_stack *a, t_stack *b, int *tab, t_range *range)
{
	int	n;
	int	in_range_index;

	n = a->size - 1;
	in_range_index = 0;
	while (range->begin != 0 && range->end != n)
	{
		while (has_num_in_range(a, range, &in_range_index))
		{
			move_to_top(a, a->bp[in_range_index]);
			if (*a->sp >= tab[range->mid])
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
	print_stack(b);
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	while(b->size)
		(move_to_top(b, b->bp[get_max(b)]), pa(a, b));
}

void	sort(t_stack *a, t_stack *b)
{
	int		*tab;
	t_range	*range;

	range = malloc(sizeof(t_range));
	tab = init_range(a, range);
	push_to_b(a, b, tab, range);
	push_back_to_a(a, b);
	(free(tab), free(range));
}
//->[x0, x1, x2, x9 , x4, x7, x6, x5, x3, x8]a
//---__--__-------------------------------__
//->[]b

/*static int	is_sorted(t_stack *a, t_stack *b)
{
	int		i;

	i = -1;
	if (b->size)
		return (0);
	while (++i < a->size - 1)
	{
		if (a->bp[i] > a->bp[i + 1])
 			return (0);
	}
	return (1);
}*/
