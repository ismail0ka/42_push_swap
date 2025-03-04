/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:35:10 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/03 04:15:16 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, char const *s2)
{
	int		i;
	int		len;
	char	*new_s;
	char	*tmp;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	new_s = malloc(len + 1);
	if (!new_s)
		return (NULL);
	i = 0;
	tmp = (char *) s1;
	while (*(tmp) != '\0')
		new_s[i++] = *(tmp++);
	tmp = (char *) s2;
	while (*(tmp) != '\0')
		new_s[i++] = *(tmp++);
	new_s[i] = '\0';
	free((void *)s1);
	return (new_s);
}
