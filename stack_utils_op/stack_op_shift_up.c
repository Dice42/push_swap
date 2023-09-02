/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_shift_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:49:09 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/20 00:56:09 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//r Shift up all elements of stack by 1.
//The first element becomes the last one.
static void	ft_r(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->top;
	if (!tmp || !tmp->next)
		return ;
	stack->top = stack->top->next;
	tmp->next = NULL;
	ft_lstlast(stack->top)->next = tmp;
}

//ra (rotate a): Shift up all elements of stack by 1.
//The first element becomes the last one.
void	ft_ra(t_stack *stack_a)
{
	ft_r(stack_a);
	write(1, "ra\n", 3);
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	ft_rb(t_stack *stack_b)
{
	ft_r(stack_b);
	write(1, "rb\n", 3);
}

//rr : ra and rb at the same time.
void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_r(stack_a);
	ft_r(stack_b);
	write(1, "rr\n", 3);
}
