/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:41:30 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/01 15:02:33 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_len(int n)
{
	int	count;

	count = 1;
	while ((n / 10) != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*alloc_buf(int n, int num_len, int is_neg)
{
	char	*new_s;

	if (is_neg)
		num_len++;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	new_s = (char *)malloc(num_len + 1);
	if (!new_s)
		return (NULL);
	if (is_neg)
		new_s[0] = '-';
	new_s[num_len--] = '\0';
	while (num_len >= 0)
	{
		if (num_len == 0 && new_s[0] == '-')
			break ;
		new_s[num_len--] = (n % 10) + 48;
		n /= 10;
	}
	return (new_s);
}

char	*ft_itoa(int n)
{
	int		curr;
	int		is_neg;
	char	*new_s;

	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		n *= -1;
		is_neg = 1;
	}
	else
		is_neg = 0;
	curr = get_int_len(n);
	new_s = alloc_buf(n, curr, is_neg);
	return (new_s);
}
