/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:31:37 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/14 21:33:17 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_list_a(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target(a, b);
	set_price(a, b);
	find_cheapest(a);
}
void	set_list_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}

void	exec_comand_a(t_all *all)
{
	t_stack	*node_to_push;

	node_to_push = cheapest_to(all->pile_a);
	above_median_comand(all, node_to_push);
	set_index(all->pile_a);
	set_index(all->pile_b);
	node_to_push = cheapest_to(all->pile_a);
	below_median_comand(all, node_to_push);
	ft_push_b(all);
}
void	exec_comand_b(t_all *all)
{
	while (all->pile_a != all->pile_b->target)
	{
		if (!all->pile_b->target->above_median)
			reverse_rotate_a(all);
		else
			rotate_a(all);
	}
	ft_push_a(all);
}
void	sorting_list(t_all *all)
{
	int		len_a;
	t_stack	*pos;

	len_a = ft_stacksize(all->pile_a);
	if (len_a-- > 3 && list_is_sorted(&all->pile_a) == 1)
		ft_push_b(all);
	if (len_a-- > 3 && list_is_sorted(&all->pile_a) == 1)
		ft_push_b(all);
	while (len_a-- > 3 && list_is_sorted(&all->pile_a) == 1)
	{
		set_list_a(all->pile_a, all->pile_b);
		exec_comand_a(all);
	}
	print_list(all->pile_a);
	print_list(all->pile_b);
	tiny_sort(&all->pile_a, all);
	while (all->pile_b)
	{
		set_list_b(all->pile_a, all->pile_b);
		exec_comand_b(all);
	}
	set_index(all->pile_a);
	pos = smaller(all->pile_a);
	while (all->pile_a != pos)
	{
		set_index(all->pile_a);
		if (!pos->above_median)
			reverse_rotate_a(all);
		else
			rotate_a(all);
	}
}
