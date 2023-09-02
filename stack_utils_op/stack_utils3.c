/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 00:43:57 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/20 00:56:23 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free2d(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	next = NULL;
	while (current)
	{
		next = current->next;
		del(current);
		current = next;
	}
	*lst = NULL;
}

t_list	*ft_lstnew(int data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->data = data;
	new->next = NULL;
	new->index = 0;
	return (new);
}

int	is_duplicate(t_stack *stack, int value)
{
	t_list	*node;

	node = stack->top;
	if (node == NULL)
		return (0);
	while (node)
	{
		if (node->data == value)
			return (1);
		node = node->next;
	}
	return (0);
}
