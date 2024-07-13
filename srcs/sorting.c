#include "push_swap.h"

bool	bigger_than(int data1, int data2)
{
	if (data1 > data2)
		return (true);
	else
		return (false);
}

int	smallest(t_all *all)
{
	int		index;
	int		small;
	t_stack	*node;

	index = 0;
	node = all->pile_a;
	small = all->pile_a->data;
	while (node->next)
	{
		if (small > node->next->data)
		{
			small = node->next->data;
			index = node->next->index;
		}
		node = node->next;
	}
	return (index);
}
int	init_cheapest(t_all *all, int *cost_price, int *index)
{
	int		small;
	t_stack	*node;
	int		i;

	i = 0;
	*index = 0;
	small = cost_price[i];
	node = all->pile_a;
	*index = node->index;
	while (node)
	{
		if (small > cost_price[i])
		{
			small = cost_price[i];
			*index = node->index;
		}
		i++;
		node = node->next;
	}
	return (small);
}

void	price_to_push_a(t_all *all, int index_a, int *price, t_instruction *is)
{
	t_stack	*list_a;

	*price = 0;
	list_a = all->pile_a;
	while (list_a->index != index_a)
	{
		list_a = list_a->next;
		++*price;
	}
	if (*price > ft_stacksize(all->pile_a) / 2)
	{
		*price = ft_stacksize(all->pile_a) - *price;
		is->rra = *price;
	}
	else
	{
		is->ra = *price;
		return ;
	}
}

void	price_to_push_b(t_all *all, int index_b, int *price, t_instruction *is)
{
	t_stack	*list_a;

	*price = 0;
	list_a = all->pile_b;
	while (list_a->index != index_b)
	{
		list_a = list_a->next;
		++*price;
	}
	if (*price > ft_stacksize(all->pile_b) / 2)
	{
		*price = ft_stacksize(all->pile_b) - *price;
		is->rrb = *price;
	}
	else
	{
		is->rb = *price;
		return ;
	}
}

void	find_target(t_all *all, int value, int *target_index)
{
	t_stack	*node_b;
	int		diff;

	node_b = all->pile_b;
	diff = value - node_b->data;
	*target_index = node_b->index;
	while (node_b != NULL)
	{
		if (value > node_b->data)
		{
			if (diff > value - node_b->data)
			{
				diff = value - node_b->data;
				*target_index = node_b->index;
			}
		}
		else if (value < node_b->data)
		{
			if (diff > node_b->data - value)
			{
				diff = node_b->data - value;
				*target_index = node_b->index;
			}
		}
		node_b = node_b->next;
	}
}

int	*init_target(t_all *all)
{
	t_stack	*a;
	int		*tab_target_index;
	int		i;

	a = all->pile_a;
	tab_target_index = malloc(sizeof(int) * ft_stacksize(a));
	i = 0;
	while (a->next)
	{
		find_target(all, a->data, &tab_target_index[i]);
		++i;
		a = a->next;
	}
	return (tab_target_index);
}

int	*init_cost(t_all *all, int *tab_target, t_instruction *comand)
{
	t_stack	*a;
	t_stack	*b;
	int		*tab_cost;
	int		i;
	int		price;
	int		j;

	a = all->pile_a;
	b = all->pile_b;
	price = 0;
	tab_cost = malloc(sizeof(int) * ft_stacksize(a) + 1);
	i = 0;
	while (a->next)
	{
		price_to_push_a(all, a->index, &price, comand);
		tab_cost[i] = price;
		++i;
		a = a->next;
	}
	j = 0;
	while (j < i)
	{
		price_to_push_b(all, tab_target[j], &price, comand);
		tab_cost[j] += price;
		++j;
	}
	return (tab_cost);
}

void	push_cheapest(t_all *all, t_instruction *is)
{
	while(is->ra != 0)
	{
		rotate_a(all);
		is->ra--;
	}
	while(is->rra != 0)
	{
		reverse_rotate_a(all);
		is->rra--;
	}
	while(is->rb != 0)
	{
		rotate_b(all);
		is->rb--;
	}
	while(is->rrb != 0)
	{
		reverse_rotate_b(all);
		is->rrb--;
	}
	ft_push_b(all);
}
t_instruction *find_comand (t_instruc_first *comand, int index)
{
	t_instruction *i;

	i = comand->first;
	while (i->next && index > 0)
	{
		i = i->next;
		index--;
	}
	return (i);
}
void	sorting_list(t_all *all)
{
	bool is_sort;

	int i;
	int *tab_target_index;
	int *tab_cost;
	int cost;
	int index_to_push;
	int nb;
	t_instruction *comand;
	t_instruc_first *first;

	t_stack *a;
	t_stack *b;

	i = 0;
	nb = ft_stacksize(all->pile_a);
	a = all->pile_a;
	b = all->pile_b;
	is_sort = false;
	print_list(all->pile_a);
	ft_push_b(all);
	ft_push_b(all);
	comand = calloc(sizeof(t_instruction) , 1);
	first = malloc(sizeof(t_instruc_first));
	first->first = comand;
	while (nb != ft_stacksize(all->pile_b) + 4)
	{
		tab_target_index = init_target(all);
		tab_cost = init_cost(all, tab_target_index, comand);
		cost = init_cheapest(all, tab_cost, &index_to_push);
		comand->next = create_instruction();
		comand = comand->next;
	}
	push_cheapest(all, find_comand(first, index_to_push));
	print_list(all->pile_b);
}