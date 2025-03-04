/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:19:03 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/12 21:10:46 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	new_s_len;
	char	*new_s;

	if (!s || !f)
		return (NULL);
	i = 0;
	new_s_len = ft_strlen(s);
	if (new_s_len <= 0)
		return (ft_strdup(""));
	new_s = (char *)malloc(new_s_len + 1);
	if (!new_s)
		return (NULL);
	while (i < new_s_len)
	{
		new_s[i] = (*f)(i, s[i]);
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
