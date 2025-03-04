/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 06:30:52 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/03 21:45:24 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

static int	has_duplicates(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (args && args[i])
	{
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

char	**validate_args(int argc, const char **argv)
{
	char	**args;
	char	*str;
	int		i;

	i = -1;
	args = NULL;
	str = NULL;
	while (--argc > 0)
	{
		str = ft_strjoin(str, argv[argc]);
		if (!str)
			exit(write(2, "Error\n", 6));
		str = ft_strjoin(str, " ");
		if (!str)
			exit(write(2, "Error\n", 6));
	}
	args = ft_split(str, ' ');
	free(str);
	if (!args)
		exit(write(2, "Error\n", 6));
	while (args[++i])
	{
		if (!is_number(args[i]))
			(free_args(args), args = NULL, exit(write(2, "Error\n", 6)));
	}
	if (has_duplicates(args))
		(free_args(args), args = NULL, exit(write(2, "Error\n", 6)));
	return (args);
}
