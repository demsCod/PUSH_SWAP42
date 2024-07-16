/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:51:34 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/16 20:12:37 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct node
{
	int			data;
	int			index;
	int			price;
	bool		above_median;
	bool		big;
	bool		small;
	bool		cheapeast;
	struct node	*target;
	struct node	*next;
}				t_stack;

typedef struct list
{
	t_stack		*first;
}				t_first;

typedef struct t_all
{
	char		**tab_char_numbers;
	long long	*tab_int_numbers;
	int			j;
	int			i;
	t_stack		*pile_a;
	t_stack		*pile_b;
}				t_all;

int				ft_stacksize(t_stack *lst);
void			rotate_a(t_all *all);
void			multi_parse(char **av, t_all *all);
void			rotate_b(t_all *all);
void			set_index(t_stack *node);
void			set_target(t_stack *a, t_stack *b);
void			set_target_b(t_stack *a, t_stack *b);
void			set_price(t_stack *a, t_stack *b);
t_stack			*bigger(t_stack *b);
t_stack			*smaller(t_stack *b);
void			find_cheapest(t_stack *node);
void			ft_free_nodes(t_stack **node);
t_stack			*cheapest_to(t_stack *node);
char			*join_command(char **av);
void			ft_push(t_stack **a, t_stack **b);
void			ft_push_b(t_all *all);
void			ft_push_a(t_all *all);
t_stack			*ft_stacklast(t_stack *lst);
void			reverse_rotate(t_stack **liste);
void			reverse_rotate_a(t_all *all);
void			reverse_rotate_b(t_all *all);
void			rotate(t_stack **liste);
void			rotate_a(t_all *all);
void			rotate_b(t_all *all);
void			ft_rot_rot(t_all *all);
void			ft_swap(t_stack **list);
void			ft_swap_a(t_all *all);
void			ft_swap_b(t_all *all);
void			move_on_top(t_all *all, t_stack *pos);
void			sorting_list(t_all *all);
void			set_list_a(t_stack *a, t_stack *b);
void			set_list_b(t_stack *a, t_stack *b);
void			exec_comand_a(t_all *all);
void			exec_comand_b(t_all *all);
void			above_median_comand(t_all *all, t_stack *node_to_push);
void			below_median_comand(t_all *all, t_stack *node_to_push);
void			ft_swap_swap(t_all *all);
int				ft_stacksize(t_stack *lst);
int				list_is_sorted(t_stack **list);
void			tiny_sort(t_stack **list, t_all *all);
t_stack			*ft_stacklast(t_stack *lst);
t_stack			*create_node(int data, int index);
void			ft_stack_back(t_stack **lst, t_stack *new);
t_stack			*last_node(t_stack **lst);
void			rev_rot_rot(t_all *all);
void			print_list(t_stack *list);
char			*join_command(char **av);
void			parse_args(char *av, t_stack **list, t_all *all);
void			free_and_exit(const char *err, int code, t_all *x);

#endif