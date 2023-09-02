/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 23:41:23 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/21 17:54:04 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_parse(t_stack *stack_a, char **av)
{
	int		i;
	int		j;
	long	value;

	j = 1;
	i = 0;
	while (av[j] != NULL)
	{
		stack_a->arr = ft_split(av[j++], ' ');
		if (stack_a->arr == NULL || !*stack_a->arr)
			return (ft_exit(stack_a));
		i = 0;
		if (stack_a->arr[i] && !ft_str_is_numeric(stack_a->arr[i]))
			return (ft_exit(stack_a));
		while (stack_a->arr[i])
		{
			value = ft_atoi(stack_a->arr[i], stack_a);
			if (!(is_duplicate(stack_a, value) == 0))
				return (ft_exit(stack_a));
			ft_add_back(stack_a, ft_lstnew(value));
			i++;
		}
		ft_free2d(stack_a->arr);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	stack_a = init_stack();
	ft_parse(stack_a, av);
	stack_b = init_stack();
	ft_add_index(stack_a);
	check_sort(stack_a, stack_b);
	ft_flush(stack_a, stack_b);
	return (0);
}
