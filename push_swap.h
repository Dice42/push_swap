/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammoh <mohammoh@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:49:54 by mohammoh          #+#    #+#             */
/*   Updated: 2023/08/20 00:39:46 by mohammoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list	*top;
	char	**arr;
	int		size;
}	t_stack;

t_list		*ft_lstnew(int data);
t_list		*ft_lstlast(t_list *lst);
char		**ft_split(char const *s, char c);
long		ft_atoi(char *str, t_stack *stack);
int			ft_str_is_numeric(char *str);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_free2d(char **arr);
int			is_duplicate(t_stack *stack, int value);
void		ft_push(t_list *new, t_stack *stack);
t_stack		*init_stack(void);
void		ft_exit(t_stack *stack);
void		ft_pop(t_stack *stack);
void		ft_swap(t_stack *stack);
int			ft_peek(t_stack *stack);
//sorting utils
int			find_min(t_stack *stack);
int			find_min_next(t_stack *stack, int min);
t_list		*find_max(t_stack *stack);
int			find_pos(t_stack *stack, int index);
int			find_pos_range(t_stack *stack, int index);

void		ft_add_back(t_stack *stack, t_list *new);
int			ft_issorted(t_stack *stack);
int			ft_isrevsorted(t_stack *stack);
// stack operations
void		ft_sa(t_stack *stack_a);
void		ft_sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		ft_pb(t_stack *stack_a, t_stack *stack_b);
void		ft_pa(t_stack *stack_a, t_stack *stack_b);
void		ft_rb(t_stack *stack_b);
void		ft_ra(t_stack *stack_a);
void		ft_rr(t_stack *stack_a, t_stack *stack_b);
void		ft_rra(t_stack *stack_a);
void		ft_rrb(t_stack *stack_b);
void		ft_rrr(t_stack *stack_a, t_stack *stack_b);
//sorting
void		check_sort(t_stack *stack_a, t_stack *stack_b);
void		ft_sort(t_stack *stack_a, t_stack *stack_b, int i, int pos);
void		ft_chunk(t_stack *stack_a, t_stack *stack_b, int max, int quarter);
void		sort5nbr(t_stack *stack_a, t_stack *stack_b);
void		sort3nbr(t_stack *stack);
void		ft_sort_big(t_stack *stack_a, t_stack *stack_b);
void		ft_add_index(t_stack *stack);
void		ft_replace_index(t_stack *stack, int min, int i);
void		ft_flush(t_stack *stack_a, t_stack *stack_b);

#endif
