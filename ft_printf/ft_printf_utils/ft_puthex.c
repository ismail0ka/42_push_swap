/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:06:13 by ikarouat          #+#    #+#             */
/*   Updated: 2025/02/13 17:25:39 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static int	ft_nbrlen(unsigned int n, unsigned int base_len)
{
	int		len;

	len = 1;
	while (n > (base_len - 1))
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_puthex(unsigned int n, char x)
{
	char			*hex;
	char			*str;
	unsigned int	nbr_len;

	if (x == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	nbr_len = ft_nbrlen(n, 16);
	str = (char *)malloc(nbr_len + 1);
	if (!str)
		return (NULL);
	str[nbr_len--] = '\0';
	while ((int)nbr_len >= 0)
	{
		str[nbr_len] = hex[n % 16];
		n /= 16;
		nbr_len--;
	}
	return (str);
}
