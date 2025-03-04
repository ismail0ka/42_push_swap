/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 01:12:12 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/09 22:06:51 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	start;

	if (!dst || !src)
		return (0);
	i = 0;
	start = ft_strlen(dst);
	if (dstsize == 0 || start >= dstsize)
		return (dstsize + ft_strlen(src));
	while (src[i] != '\0' && start + i < dstsize - 1)
	{
		dst[start + i] = src[i];
		i++;
	}
	dst[start + i] = '\0';
	return (start + ft_strlen(src));
}
