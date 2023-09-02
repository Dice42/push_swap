/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:08:08 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/20 00:56:16 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//function to initialize an empty stack
t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	if (stack)
	{
		stack->top = NULL;
		stack->arr = 0;
		stack->size = 0;
	}
	return (stack);
}

// function to add a node to the top of the stack
void	ft_push(t_list *new, t_stack *stack)
{
	if (!stack && !new)
		return ;
	new->next = stack->top;
	stack->top = new;
	stack->size++;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_add_back(t_stack *stack, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(stack->top);
	if (!last)
		stack->top = new;
	else
		last->next = new;
	stack->size++;
}

void	ft_exit(t_stack *stack)
{
	ft_free2d(stack->arr);
	ft_lstclear(&stack->top, free);
	free(stack);
	write(2, "Error\n", 6);
	exit(1);
}
