/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:51:34 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/13 04:18:31 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_instruction
{
	size_t			rra;
	size_t			ra;
	size_t			rrb;
	size_t			rb;
}					t_instruction;
typedef struct node
{
	int				data;
	int				index;
	int				price;
	bool			above_median;
	bool			big;
	bool			small;
	bool			cheapeast;
	struct node		*target;
	t_instruction	instruction;
	struct node		*next;
}					t_stack;

typedef struct list
{
	t_stack			*first;
}					t_first;

typedef struct t_all
{
	t_stack			*pile_a;
	t_stack			*pile_b;
	t_instruction	*x;
	int				n_numbers;
}					t_all;

int					ft_stacksize(t_stack *lst);
void				rotate_a(t_all *all);
void				rotate_b(t_all *all);
t_instruction		*create_instruction(void);
char				*join_command(char **av);
void				ft_push(t_stack **a, t_stack **b);
void				ft_push_b(t_all *all);
void				ft_push_a(t_all *all);
t_stack				*ft_stacklast(t_stack *lst);
void				reverse_rotate(t_stack **liste);
void				reverse_rotate_a(t_all *all);
void				reverse_rotate_b(t_all *all);
void				rotate(t_stack **liste);
void				rotate_a(t_all *all);
void				rotate_b(t_all *all);
void				ft_rot_rot(t_all *all);
void				ft_swap(t_stack **list);
void				ft_swap_a(t_all *all);
void				ft_swap_b(t_all *all);
void				sorting_list(t_all *all);
void				ft_swap_swap(t_all *all);
int					ft_stacksize(t_stack *lst);
int					list_is_sorted(t_stack **list);
void				tiny_sort(t_stack **list, t_all *all);
t_stack				*ft_stacklast(t_stack *lst);
t_stack				*create_node(int data, int index);
void				ft_stack_back(t_stack **lst, t_stack *new);
t_stack				*last_node(t_stack **lst);
void				rev_rot_rot(t_all *all);
void				ft_remove_first(t_stack **a);
void				print_list(t_stack *list);
char				*join_command(char **av);
void				parse_args(char *av, t_stack **list, t_all *all);
void				presort(t_all *all);

#endif