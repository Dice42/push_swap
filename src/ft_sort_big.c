/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:09:00 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/20 00:55:55 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort(t_stack *stack_a, t_stack *stack_b, int i, int pos)
{
	while (stack_a->size != 3 && !ft_issorted(stack_a))
	{
		pos = find_pos(stack_a, i++);
		if (pos == 0)
			ft_pb(stack_a, stack_b);
		else if (pos <= stack_a->size - pos)
		{
			while (pos--)
				ft_ra(stack_a);
			ft_pb(stack_a, stack_b);
		}
		else if (pos > stack_a->size - pos)
		{
			pos = stack_a->size - pos;
			while (pos--)
				ft_rra(stack_a);
			ft_pb(stack_a, stack_b);
		}
	}
	sort3nbr(stack_a);
	while (stack_b->top)
		ft_pa(stack_a, stack_b);
	ft_add_index(stack_a);
}

static void	ft_chunk2(t_stack *stack_a, t_stack *stack_b, int max, int quarter)
{
	int	pos;

	while (stack_a->size != (max - quarter) && stack_a->size != 3)
	{
		if (max - quarter == 0)
			quarter -= 3;
		if (max - quarter < 10)
			quarter -= (3 - (max % quarter));
		pos = find_pos_range(stack_a, (quarter - 1));
		if (pos == 0 && stack_a->size != 3)
			ft_pb(stack_a, stack_b);
		if (pos <= stack_a->size - pos && pos != 0)
		{
			while (pos--)
				ft_ra(stack_a);
			if (stack_a->top->index <= quarter / 2)
			{
				ft_pb(stack_a, stack_b);
				ft_rb(stack_b);
			}
			else
				ft_pb(stack_a, stack_b);
		}
	}
}

static void	ft_chunk3(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;
	int	i;

	i = find_max(stack_b)->index;
	sort3nbr(stack_a);
	while (stack_b->size != 0)
	{
		pos = find_pos(stack_b, i--);
		if (pos == 0)
			ft_pa(stack_a, stack_b);
		else if (pos <= stack_b->size - pos)
		{
			while (pos--)
				ft_rb(stack_b);
			ft_pa(stack_a, stack_b);
		}
		else if (pos > stack_b->size - pos)
		{
			pos = stack_b->size - pos;
			while (pos--)
				ft_rrb(stack_b);
			ft_pa(stack_a, stack_b);
		}
	}
	ft_add_index(stack_a);
}

void	ft_chunk(t_stack *stack_a, t_stack *stack_b, int max, int quarter)
{
	while (stack_a->size != 3 && !ft_issorted(stack_a))
	{
		ft_chunk2(stack_a, stack_b, max, quarter);
		max = stack_a->size;
		ft_add_index(stack_a);
		ft_add_index(stack_b);
	}
	ft_chunk3(stack_a, stack_b);
}
