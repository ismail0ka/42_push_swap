/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:00:19 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/03 02:50:53 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*new_s;
	size_t	s_len;

	if (!s1)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s1);
	new_s = (char *)malloc(s_len + 1);
	if (!new_s)
		return (NULL);
	while (i < s_len)
	{
		new_s[i] = s1[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
