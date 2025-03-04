/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:10:29 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/07 21:42:06 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;	

	if (!haystack)
		return (NULL);
	if (!(*needle))
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp((const char *)
					(haystack + i), needle, ft_strlen(needle)) == 0
				&& i + ft_strlen(needle) <= len)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
