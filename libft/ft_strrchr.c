/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:41:18 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/10 19:13:33 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((char) c == '\0')
		return ((char *)(s + s_len));
	s_len--;
	while (s_len >= 0)
	{
		if (s[s_len] == (char) c)
			return ((char *)(s + s_len));
		s_len--;
	}
	return (NULL);
}
