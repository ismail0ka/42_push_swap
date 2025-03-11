/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:16:08 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/11 06:37:25 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a);

static int	choose_pivot(t_stack *a)
{
	int	i;
	int	pivot;
	int	*tab;

	tab = malloc(a->size * sizeof(int));
	if (!tab)
		(write(2, "Error\n", 6), exit(1));
	i = 0;
	while (i < a->size)
	{
		tab[i] = a->bp[i];
		i++;
	}
	quick_sort(tab, 0, a->size - 1);
	pivot = tab[a->size / 2];
	return (free(tab), pivot);
}


static int	has_sub_pivot(t_stack *a, int pivot,int *j)
{
	int	i;

	i = a->size - 1;
	while (i--)
	{
		if (a->bp[i] <= pivot)
			return  (*j = i, 1);
	}
	return (0);
}

static void	push_to_b(t_stack *a, t_stack *b, int pivot)
{
	int	i;

	i = 0;
	while (has_sub_pivot(a, pivot, &i))
		(move_to_top(a, a->bp[i]), pb(a, b));
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	while(b->size)
		(move_to_top(b, b->bp[get_max(b)]), pa(a, b));
}

static int	is_sorted(t_stack *a, t_stack *b)
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
}

void	sort(t_stack *a, t_stack *b)
{
	//BOT_B range [0, n/4]
	//TOP_B range [n/4, n/2]
	//TOP_A range [n/2, n - (n/4)]
	//BOT_A range [n - (n/4), n]
	//for each elem:
		//if element in BOT_B range:
			//pb and (if b->size > 2: rb; else: sb)
		//else if element in TOP_B range:
			//pb
		//else if element in TOP_A range:
			//NO OP
		//else
			//ra
	//TO DO: ADD CHUNKING
	int	pivot;

	if (a->size <= 1 || is_sorted(a, b))
	{
		if (a->size == 1)
			pb(a, b);
		return ;
	}
	pivot = choose_pivot(a);
	push_to_b(a, b, pivot);
	sort(a, b);
	push_back_to_a(a, b);
}
//->[x0, x1, x2, x9 , x4, x7, x6, x5, x3, x8]a
//---__--__-------------------------------__
//->[]b