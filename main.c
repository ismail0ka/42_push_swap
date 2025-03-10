/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:07:38 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/07 01:33:55 by ikarouat         ###   ########.fr       */
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

	a = ft_stack_new(count);
	i = 0;
	while (args && *args)
	{
		a->bp[i] = ft_atoi(*args);
		args++;
		i++;
	}
	a->sp = &a->bp[count - 1];
	return (a);
}
void print_stack(t_stack *x);

int	main(int argc, const char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	//INIT STACKS
	if (argc < 2 || has_empty_str(argv))
		exit(write(2, "Error\n", 6));
	args = validate_args(argc, argv);
	if (!args)
		exit(write(2, "Error\n", 6));
	a = init_stack(count_args(args), args);
	free_args(args);
	//write(1, "Valid\n", 6);
	b = ft_stack_new(count_args(args));
	b->size = 0;
	b->sp = b->bp;
	//SORTING
	ft_printf("Pre sort: ");
	print_stack(a);
	print_stack(b);
	if (a->size <= 5)
		short_sort(a, b);
	else
		sort(a, b);
	ft_printf("Post sort: ");
	print_stack(a);
	print_stack(b);
	(free(a->bp), free(a));
	(free(b->bp), free(b));
	return (0);
}

void	print_stack(t_stack *a)
{
	int i=0;
	while (i < a->size)
	{
		ft_printf("%d ", a->bp[i]);
		i++;
	}
	write(1, "\n", 1);
}