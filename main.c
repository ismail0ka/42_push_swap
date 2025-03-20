/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:07:38 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/20 04:18:46 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

static t_stack	*init_stack(int count, char **args)
{
	t_stack	*a;
	int		i;
	int		j;

	a = ft_stack_new(count);
	i = 0;
	j = count - 1;
	while (j >= 0)
	{
		a->bp[i] = ft_atoi(args[j]);
		i++;
		j--;
	}
	a->sp = &a->bp[count - 1];
	a->name = 'a';
	return (a);
}

int	main(int argc, const char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	if (argc < 2 || has_empty_str(argv))
		exit(write(2, "Error\n", 6));
	args = validate_args(argc, argv);
	if (!args)
		exit(write(2, "Error\n", 6));
	a = init_stack(count_args(args), args);
	b = ft_stack_new(count_args(args));
	b->size = 0;
	b->sp = b->bp;
	b->name = 'b';
	free_args(args);
	if (!is_sorted(a))
	{
		if (a->size <= 5)
			short_sort(a, b);
		else
			sort(a, b);
	}
	(free(a->bp), free(a));
	(free(b->bp), free(b));
	return (0);
}

/*void	print_stack(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		ft_printf("%d ", a->bp[i]);
		i++;
	}
	write(1, "\n", 1);
}*/
