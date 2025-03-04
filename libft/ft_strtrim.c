/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:08:59 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/10 15:38:45 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char			*new_s;
	const char		*s_end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	s_end = s1 + ft_strlen(s1) - 1;
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (*s1 == '\0')
		return (ft_strdup(""));
	while (s_end > s1 && ft_strchr(set, *s_end))
		s_end--;
	new_s = (char *)malloc(s_end - s1 + 2);
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s1, s_end - s1 + 2);
	return (new_s);
}
