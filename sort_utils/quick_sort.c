/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:42:11 by ikarouat          #+#    #+#             */
/*   Updated: 2025/02/26 00:33:22 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *tab, int low, int high)
{
	int	pivot;
	int	i;
	int j;

	pivot = tab[high];
	i = low - 1;
	j = low - 1;
	while (++j < high)
	{
		if (tab[j] <= pivot)
			swap(&tab[++i], &tab[j]);
	}
	swap(&tab[i+1], &tab[high]);
	return (i+1);
}


void	quick_sort(int *tab, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(tab, low, high);

		quick_sort(tab, low, pivot - 1);
		quick_sort(tab, pivot + 1, high);
	}	
}
