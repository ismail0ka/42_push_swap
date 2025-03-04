/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:07:04 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/13 23:15:13 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;

	if (!dst)
		return (NULL);
	if (!src)
		return (dst);
	tmp_d = dst;
	tmp_s = (unsigned char *)src;
	while (n > 0)
	{
		*(tmp_d++) = *(tmp_s++);
		n--;
	}
	return (dst);
}
