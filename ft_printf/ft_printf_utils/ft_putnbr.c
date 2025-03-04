/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 03:13:42 by ikarouat          #+#    #+#             */
/*   Updated: 2025/02/13 17:05:40 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static int	ft_nbrlen(int n, int base_len)
{
	int		len;

	len = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > (base_len - 1))
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_putnbr(int n)
{
	char	*str;
	int		nbr_len;

	nbr_len = ft_nbrlen(n, 10);
	str = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	str[nbr_len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	nbr_len--;
	while (nbr_len >= 0)
	{
		str[nbr_len] = n % 10 + '0';
		n /= 10;
		if (n == 0 && str[0] == '-')
			break ;
		nbr_len--;
	}
	return (str);
}
