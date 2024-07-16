/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instrucion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:49:49 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/09 20:07:12 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_push(t_stack **a, t_stack **b)
{
	t_stack *pb;

	if (a)
	{
		pb = (*a);
		(*a) = (*a)->next;
		pb->next = *b;
		*b = pb;
	}
	return ;
}

void ft_push_a(t_all *all)
{
	if(!all->pile_b)
		return;
	ft_push(&all->pile_b, &all->pile_a);
	ft_putendl_fd("pa", 1);
	return ;
}

void ft_push_b(t_all *all)
{
	ft_push(&all->pile_a, &all->pile_b);
	ft_putendl_fd("pb", 1);
	return ;
}