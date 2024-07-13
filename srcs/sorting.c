#include "push_swap.h"

t_stack	*bigger(t_stack *b)
{
	long		big;
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
	long		small;
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

void find_cheapest(t_stack *node)
{
	t_stack *cheapest_node;
	long price;

	if (!node)
		return;
	price = 2147483648;
	while(node)
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
void set_list_a(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target(a, b);
	set_price(a, b);
	find_cheapest(a);
}
void set_list_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}
t_stack	*cheapest_to(t_stack *node)
{
	t_stack *cheap;

	cheap = node;
	while (node)
	{
		if (node->cheapeast == true)
			cheap = node;
		node = node->next;
	}
	return (cheap);
}
void above_median_comand(t_all *all, t_stack *node_to_push)
{
	if (node_to_push->above_median && node_to_push->target->above_median)
	{
		while (all->pile_a != node_to_push && all->pile_b != node_to_push->target)
			rev_rot_rot(all);
	}
	if (node_to_push->above_median)
	{
		while (all->pile_a != node_to_push)
			reverse_rotate_a(all);
	}
	if (node_to_push->target->above_median)
	{
		while (all->pile_b != node_to_push->target)
			reverse_rotate_b(all);
	}
}

void below_median_comand(t_all *all, t_stack *node_to_push)
{
	if ((!node_to_push->above_median) && (!node_to_push->target->above_median))
	{
		while (all->pile_a != node_to_push && all->pile_b != node_to_push->target)
			ft_rot_rot(all);
	}
	if ((!node_to_push->above_median))
	{
		while (all->pile_a != node_to_push)
			rotate_a(all);
	}
	if (!node_to_push->target->above_median)
	{
		while (all->pile_b != node_to_push->target)
			rotate_b(all);
	}
}

void exec_comand_a(t_all *all)
{
	t_stack *node_to_push;

	node_to_push = cheapest_to(all->pile_a);
	above_median_comand(all, node_to_push);
	below_median_comand(all, node_to_push);
	ft_push_b(all);

}
void exec_comand_b(t_all *all)
{
	while(all->pile_a != all->pile_b->target)
	{
		if(!all->pile_b->target->above_median)
			reverse_rotate_a(all);
		else
			rotate_a(all);
	}
	ft_push_a(all);

}
void	sorting_list(t_all *all)
{
	int len_a;
	t_stack *pos;
	len_a = ft_stacksize(all->pile_a);
	if (len_a-- > 3 && list_is_sorted(&all->pile_a) == 1)
		ft_push_b(all);
	if (len_a-- > 3 && list_is_sorted(&all->pile_a) == 1)
		ft_push_b(all);
	while(len_a-- > 3 && list_is_sorted(&all->pile_a) == 1)
	{
		set_list_a(all->pile_a, all->pile_b);
		exec_comand_a(all);
	}
	tiny_sort(&all->pile_a, all);
	while(all->pile_b)
	{
		set_list_b(all->pile_a, all->pile_b);
		exec_comand_b(all);
	}
	set_index(all->pile_a);
	pos = smaller(all->pile_a);
	print_list(all->pile_a);
	while(all->pile_a != pos)
	{
		if (!pos->above_median)
			reverse_rotate_a(all);
		else
			rotate_a(all);
	}
	print_list(all->pile_a);
}