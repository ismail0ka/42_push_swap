/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 03:16:37 by ikarouat          #+#    #+#             */
/*   Updated: 2025/01/16 18:42:06 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static size_t	ft_ptrlen(uintptr_t ptr)
{
	size_t	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr > 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

char	*ft_putptr(uintptr_t ptr)
{
	size_t	ptr_len;
	char	*str;

	if (ptr == 0)
		return (NULL);
	ptr_len = ft_ptrlen(ptr);
	str = (char *)malloc(sizeof(char) * (ptr_len + 3));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	str[ptr_len + 2] = '\0';
	while (ptr_len > 0)
	{
		if (ptr % 16 < 10)
			str[ptr_len + 1] = ptr % 16 + '0';
		else
			str[ptr_len + 1] = ptr % 16 + 'a' - 10;
		ptr /= 16;
		ptr_len--;
	}
	return (str);
}
