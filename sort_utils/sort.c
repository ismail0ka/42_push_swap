/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:16:08 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/08 05:57:16 by ikarouat         ###   ########.fr       */
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

static void	push_to_b(t_stack *a, t_stack *b, int pivot)
{
	int	i;

	//repeat while a num <= pivot exists in a 
		//look for min number
		//find cheapest way to get it to top of stack a
		//pb
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	i;

	i = b->size;
	while(i--)
	{
		if (*(b->sp) > b->bp[b->size - 1])
			sx(b);
		pa(a, b);
	}
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
	int	pivot;

	if (a->size <= 1 || is_sorted(a, b))
		return ;
	(ft_printf("A:"), print_stack(a));
	(ft_printf("B:"), print_stack(b));
	pivot = choose_pivot(a);
	ft_printf("Pivot: %d\n", pivot);
	push_to_b(a, b, pivot);
	sort(a, b);
	push_back_to_a(a, b);
}
//->[x0, x1, x2, x9 , x4, x7, x6, x5, x3, x8]a
//---__--__-------------------------------__
//->[]b