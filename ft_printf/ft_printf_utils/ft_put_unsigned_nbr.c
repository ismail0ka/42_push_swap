/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 03:15:18 by ikarouat          #+#    #+#             */
/*   Updated: 2025/01/30 18:56:26 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static size_t	ft_nbrlen(unsigned int nbr)
{
	size_t		len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_put_unsigned_nbr(unsigned int nbr)
{
	size_t		n_len;
	char		*str;

	n_len = ft_nbrlen(nbr);
	str = malloc(n_len + 1);
	if (!str)
		return (NULL);
	str[n_len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[--n_len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
