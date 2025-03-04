/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:53:09 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/25 22:50:00 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*heap_arr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	heap_arr = malloc(count * size);
	if (!heap_arr)
		return (NULL);
	ft_bzero(heap_arr, count * size);
	return (heap_arr);
}
