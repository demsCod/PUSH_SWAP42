/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:29:31 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/16 20:47:18 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*bigger(t_stack *b)
{
	long	big;
	t_stack	*node;

	node = b;
	big = -2147483647;
	while (b)
	{
		if (big < b->data)
		{
			big = b->data;
			node = b;
		}
		b = b->next;
	}
	return (node);
}

t_stack	*smaller(t_stack *b)
{
	long	small;
	t_stack	*node;

	node = b;
	small = 2147483649;
	while (b)
	{
		if (small > b->data)
		{
			small = b->data;
			node = b;
		}
		b = b->next;
	}
	return (node);
}

void	find_cheapest(t_stack *node)
{
	t_stack	*cheapest_node;
	long	price;

	if (!node)
		return ;
	price = 2147483648;
	while (node)
	{
		if (node->price < price)
		{
			price = node->price;
			cheapest_node = node;
		}
		node = node->next;
	}
	cheapest_node->cheapeast = true;
}

t_stack	*cheapest_to(t_stack *node)
{
	t_stack	*cheap;

	cheap = node;
	while (node)
	{
		if (node->cheapeast == true)
			cheap = node;
		node = node->next;
	}
	return (cheap);
}

void	move_on_top(t_all *all, t_stack *pos)
{
	while (all->pile_a != pos)
	{
		set_index(all->pile_a);
		if (!pos->above_median)
			reverse_rotate_a(all);
		else
			rotate_a(all);
	}
}
