/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:07:38 by ikarouat          #+#    #+#             */
/*   Updated: 2025/02/12 02:40:41 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_number(char *str){
	if (*str != '-' || *str != '+' || !ft_isdigit(*str))
		return (0);
	while (*str){
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static void	validate_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			write(1, "Error\n", 6);
			exit(-1);
		}
		i++;
	}
}

static t_stack	*init_stack(int argc, char **argv){
	int		i;
	t_stack *a;

	i = 0;
	a = ft_stack_new(argc - 1);
	if (!a)
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
	while (i < argc - 1){
		a->elm[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	a->sp = &a->elm[i - 1];
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	//INIT STACKS
	validate_args(argc, argv);
	a = init_stack(argc, argv);
	b = ft_stack_new(argc);
	b->size = 0;
	b->sp = &b->elm;
	//SORTING
	if (a->size <= 5)
		short_sort(a);
	else
		sort(a, b);
	return (0);
}
