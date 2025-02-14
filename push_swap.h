/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:07:49 by ikarouat          #+#    #+#             */
/*   Updated: 2025/02/04 16:15:51 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
typedef struct s_stack
{
	int	*elm;
	int	*sp;
	int	size;
}	t_stack;

t_stack	*ft_stack_new(int);
void	sa(t_stack *);
void	sb(t_stack *);
void	ss(t_stack *, t_stack *);

void	pa(t_stack *to, t_stack *from);
void	pb(t_stack *to, t_stack *from);

void	ra(t_stack *);
void	rb(t_stack *);
void	rr(t_stack *, t_stack *);

void	rra(t_stack *);
void	rrb(t_stack *);
void	rrr(t_stack *, t_stack *);


void   sort(t_stack *a, t_stack *b);
#endif //PUSH_SWAP_H