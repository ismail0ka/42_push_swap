/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:03:16 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/18 04:06:02 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *a)
{
	int	i;
	int	max_index;

	i = 0;
	max_index = 0;
	while (i < a->size)
	{
		if (a->bp[i] > a->bp[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}
