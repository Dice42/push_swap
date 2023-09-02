/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:29:38 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/20 00:55:41 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_issorted(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->top;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_isrevsorted(t_stack *stack)
{
	t_list	*tmp;

	if (!stack->top || !stack->top->next)
		return (0);
	tmp = stack->top;
	while (tmp && tmp->next)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	find_min(t_stack *stack)
{
	t_list	*tmp;
	t_list	*min;

	tmp = stack->top;
	min = stack->top;
	while (tmp)
	{
		if (tmp->data < min->data)
			min = tmp;
		tmp = tmp->next;
	}
	return (min->data);
}

int	find_min_next(t_stack *stack, int min)
{
	t_list	*tmp;
	int		min_next;

	tmp = stack->top;
	min_next = INT_MAX;
	while (tmp)
	{
		if (tmp->data < min_next && (tmp->data > min))
			min_next = tmp->data;
		tmp = tmp->next;
	}
	return (min_next);
}

t_list	*find_max(t_stack *stack)
{
	t_list	*tmp;
	t_list	*max;

	tmp = stack->top;
	max = stack->top;
	while (tmp)
	{
		if (tmp->data > max->data)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}
