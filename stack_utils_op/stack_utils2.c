/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:59:45 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/20 00:56:20 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//removes the top elements of stack and returns its value
void	ft_pop(t_stack *stack)
{
	t_list	*node;

	if (!stack->top)
		return ;
	node = stack->top;
	if (node->next)
		stack->top = node->next;
	else
		stack->top = NULL;
	stack->size--;
	free(node);
}

//return the value of the top element with out removing it from the stack
int	ft_peek(t_stack *stack)
{
	return (stack->top->data);
}

//swaps the top two elements of the stack 
void	ft_swap(t_stack *stack)
{
	int	temp;

	if (!stack->top || !stack->top->next)
		return (ft_exit(stack));
	temp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = temp;
}

void	ft_flush(t_stack *stack_a, t_stack *stack_b)
{
	ft_lstclear(&stack_a->top, free);
	ft_lstclear(&stack_b->top, free);
	free(stack_a);
	free(stack_b);
}
