/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:05:14 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/20 00:55:45 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//getting the indexes
void	ft_replace_index(t_stack *stack, int min, int i)
{
	t_list	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (tmp->data == min)
			break ;
		tmp = tmp->next;
	}
	tmp->index = i;
}

//function to add indexes;
void	ft_add_index(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = find_min(stack);
	while (i < stack->size)
	{
		ft_replace_index(stack, min, i);
		min = find_min_next(stack, min);
		i++;
	}
}

//return the position of the node
int	find_pos(t_stack *stack, int index)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->index == index)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	find_pos_range(t_stack *stack, int index)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->index <= index)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}
