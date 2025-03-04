/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:02:44 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/04 05:23:33 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_min(t_stack *a)
{
	int	i;
	int	min_index;

	i = 0;
	min_index = -1;
	while (i < a->size)
	{
		if (a->bp[i] < a->bp[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}