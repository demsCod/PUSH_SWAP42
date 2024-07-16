/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:33:56 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/14 17:36:04 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void above_median_comand(t_all *all, t_stack *node_to_push)
{
	if (node_to_push->above_median && node_to_push->target->above_median)
	{
		while (all->pile_a != node_to_push && all->pile_b != node_to_push->target)
		{
			ft_rot_rot(all);
		}
	}
	set_index(all->pile_a);
	set_index(all->pile_b);
	node_to_push = cheapest_to(all->pile_a);
	if (node_to_push->above_median)
	{
		while (all->pile_a != node_to_push)
			rotate_a(all);
	}
	if (node_to_push->target->above_median)
	{
		while (all->pile_b != node_to_push->target)
			rotate_b(all);
	}
}

void below_median_comand(t_all *all, t_stack *node_to_push)
{
	if ((!node_to_push->above_median) && (!node_to_push->target->above_median))
	{
		while (all->pile_a != node_to_push && all->pile_b != node_to_push->target)
			rev_rot_rot(all);
	}
	set_index(all->pile_a);
	set_index(all->pile_b);
	node_to_push = cheapest_to(all->pile_a);
	if ((!node_to_push->above_median))
	{
		while (all->pile_a != node_to_push)
			reverse_rotate_a(all);
	}
	if (!node_to_push->target->above_median)
	{
		while (all->pile_b != node_to_push->target)
			reverse_rotate_b(all);
	}
}
