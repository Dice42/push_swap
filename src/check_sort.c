/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 22:22:40 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/20 00:55:49 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort3nbr(t_stack *stack)
{
	if (ft_isrevsorted(stack))
	{
		ft_ra(stack);
		ft_sa(stack);
	}
	else if ((stack->top->data > stack->top->next->data) 
		&& (stack->top->data < stack->top->next->next->data)
		&& (stack->top->next->data < stack->top->next->next->data))
		ft_sa(stack);
	else if ((stack->top->data < stack->top->next->data) 
		&& (stack->top->data < stack->top->next->next->data)
		&& (stack->top->next->data > stack->top->next->next->data))
	{
		ft_rra(stack);
		ft_sa(stack);
	}
	else if ((stack->top->data > stack->top->next->data) 
		&& (stack->top->data > stack->top->next->next->data)
		&& (stack->top->next->data < stack->top->next->next->data))
		ft_ra(stack);
	else if ((stack->top->data < stack->top->next->data) 
		&& (stack->top->data > stack->top->next->next->data)
		&& (stack->top->next->data > stack->top->next->next->data))
		ft_rra(stack);
}

void	sort5nbr(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size != 3)
	{
		if (stack_a->top->index == 0 || stack_a->top->index == 1)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
	sort3nbr(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	if (stack_a->top->data > stack_a->top->next->data)
		ft_sa(stack_a);
}

void	check_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_issorted(stack_a) && stack_b->size == 0)
		return ;
	else if (stack_a->size == 2)
	{
		if (stack_a->top->data > stack_a->top->next->data)
			ft_sa(stack_a);
	}
	else if (stack_a->size == 3)
		sort3nbr(stack_a);
	else if (stack_a->size == 5)
		sort5nbr(stack_a, stack_b);
	else if (stack_a->size < 55)
		ft_sort(stack_a, stack_b, 0, 0);
	else if (stack_a->size <= 200)
		ft_chunk(stack_a, stack_b, stack_a->size, stack_a->size / 5);
	else if (stack_a->size > 200)
		ft_chunk(stack_a, stack_b, stack_a->size, stack_a->size / 10);
}
