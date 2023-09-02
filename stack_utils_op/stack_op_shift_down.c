/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_shift_down.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:46:07 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/20 00:56:06 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rra Shift down all elements of stack by 1.
// The last element becomes the first one.

static void	ft_rrrr(t_stack *stack)
{
	t_list	*tmp;
	t_list	*end;

	if (!stack || !(stack->top->next))
		return ;
	tmp = stack->top;
	end = ft_lstlast(stack->top);
	while (stack->top->next->next)
		stack->top = stack->top->next;
	end->next = tmp;
	stack->top->next = NULL;
	stack->top = end;
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	ft_rra(t_stack *stack_a)
{
	ft_rrrr(stack_a);
	write(1, "rra\n", 4);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	ft_rrb(t_stack *stack_b)
{
	ft_rrrr(stack_b);
	write(1, "rrb\n", 4);
}

//rrr : rra and rrb at the same time.
void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
	write(1, "rrr\n", 4);
}
