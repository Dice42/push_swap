/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:33:25 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/20 00:56:13 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//sa --> swap the first two elements at the top of stack a, 
//do nothing if there's only one or no element
void	ft_sa(t_stack *stack_a)
{
	if (!stack_a || !stack_a->top->next)
		return ;
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

//sb (swap b): Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.

void	ft_sb(t_stack *stack_b)
{
	if (!stack_b || !stack_b->top->next)
		return ;
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

//ss : sa and sb at the same time
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
	write(1, "ss\n", 3);
}
