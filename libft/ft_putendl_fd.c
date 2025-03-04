/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:37:07 by ikarouat          #+#    #+#             */
/*   Updated: 2024/11/12 21:03:39 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	unsigned char	new_line;

	if (fd < 0 || !s)
		return ;
	new_line = '\n';
	ft_putstr_fd(s, fd);
	write(fd, &new_line, 1);
}
