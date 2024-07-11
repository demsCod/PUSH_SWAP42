/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:44:43 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/09 19:59:21 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate(t_stack **liste)
{
	t_stack *last;

	if((*liste)->next == NULL)
	{
		return;
	}
	last = *liste;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = (*liste);
	(*liste) = (*liste)->next;
	last->next->next = NULL;
}
void rotate_a(t_all *all)
{
	rotate(&all->pile_a);
	ft_putendl_fd("ra", 1);
}

void rotate_b(t_all *all)
{
	rotate (&all->pile_b);
	ft_putendl_fd("rb", 1);
}

void ft_rot_rot(t_all *all)
{
	rotate(&all->pile_a);
	rotate(&all->pile_b);
	ft_putendl_fd("rr", 1);
}
