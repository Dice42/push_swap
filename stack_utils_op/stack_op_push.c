/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:10:46 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/20 00:56:03 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//pa (push a): Take the first element at the top 
//of b and put it at the top of a.
//Do nothing if b is empty.
void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	long	top;

	if (!stack_b)
		return ;
	top = ft_peek(stack_b);
	ft_push(ft_lstnew(top), stack_a);
	ft_pop(stack_b);
	write(1, "pa\n", 3);
}

//pb (push b): Take the first element at the top 
//of a and put it at the top of b.
//Do nothing if a is empty
void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	long	top;

	if (!stack_a)
		return ;
	top = ft_peek(stack_a);
	ft_push(ft_lstnew(top), stack_b);
	ft_pop(stack_a);
	write(1, "pb\n", 3);
}
