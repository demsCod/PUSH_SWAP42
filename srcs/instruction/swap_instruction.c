/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:42:25 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/09 19:56:37 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack **list)
{
	t_stack	*first;

	t_stack *tmp;

	if (!list || !(*list) || !(*list)->next)
		return ;
	first = *list;
	if (first->next)
	{
		tmp = first->next;
		first->next = first->next->next;
		tmp->next = first;
		(*list) = tmp;
	}
}

void	ft_swap_b(t_all *all)
{
	ft_swap(&all->pile_b);
	ft_putendl_fd("sb", 1);
}
void	ft_swap_a(t_all *all)
{
	ft_swap(&all->pile_a);
	ft_putendl_fd("sa", 1);
}
void ft_swap_swap(t_all *all)
{
	ft_swap_a(all);
	ft_swap_b(all);
	ft_putendl_fd("ss", 1);
}