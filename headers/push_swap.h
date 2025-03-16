/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:07:49 by ikarouat          #+#    #+#             */
/*   Updated: 2025/03/16 21:36:05 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_stack
{
	int		*bp;
	int		*sp;
	int		size;
	char	name;
}	t_stack;

typedef struct s_range
{
	int	begin;
	int	mid;
	int	end;
	int	offset;
}	t_range;

int		has_empty_str(const char **args);
char	**validate_args(int argc, const char **argv);
void	free_args(char **args);

t_stack	*ft_stack_new(int size);

void	sx(t_stack *s);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *to, t_stack *from);
void	pb(t_stack *to, t_stack *from);

void	rx(t_stack *s);
void	rr(t_stack *a, t_stack *b);
void	rrx(t_stack *s);
void	rrr(t_stack *a, t_stack *b);

int		get_min(t_stack *a);
int		get_max(t_stack *a);
void	move_to_top(t_stack *stack, int x);
void	short_sort(t_stack *a, t_stack *b);
void	quick_sort(int *a, int low, int high);
void	sort(t_stack *a, t_stack *b);
#endif //PUSH_SWAP_H
