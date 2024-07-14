/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 17:45:43 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/14 17:46:23 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_index (t_stack *node)
{
	int	i;
	int len;
	if (!node)
		return;
	i = 0;
	len = ft_stacksize(node);
	while (node)
	{
		node->index = i;
		if (i <= len / 2)
			node->above_median = true;
		else
			node->above_median = false;
		++i;
		node = node->next;
	}
}

void set_target (t_stack *a, t_stack *b)
{
	t_stack *target;
	t_stack *temp_b;
	long diff;

	while (a)
	{
		temp_b = b;
		diff = -2147483647;
		while(temp_b)
		{
			if (temp_b->data < a->data && temp_b->data > diff)
			{
				diff = temp_b->data;
				target = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (diff == -2147483647)
			a->target = bigger(b);
		else
			a->target = target;
		a = a->next;
	}
}

void set_target_b (t_stack *a, t_stack *b)
{
	t_stack *target;
	t_stack *current_a;
	long diff;

	while (b)
	{
		current_a = a;
		diff = 2147483648;
		while(current_a)
		{
			if (current_a->data > b->data && current_a->data < diff)
			{
				diff = current_a->data;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (diff == 2147483648)
			b->target = smaller(a);
		else
			b->target = target;
		b = b->next;
	}
}
void set_price(t_stack *a, t_stack *b)
{
	int len_a;
	int len_b;

	len_a = ft_stacksize(a);
	len_b = ft_stacksize(b);
	while (a)
	{
		if (a->above_median == true)
			a->price = a->index;
		else
			a->price = len_a - a->index;
		if (a->target->above_median == true)
			a->price += a->target->index;
		else
			a->price += len_b - a->target->index;
		a = a->next;
	}
}