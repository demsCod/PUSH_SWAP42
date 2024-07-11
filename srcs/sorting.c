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

int	price_to_push(t_stack **list, int index)
{
	t_stack	*node;

	node = *list;
	if (index == 0)
		return (1);
	while (index != 0)
	{
		node = node->next;
		--index;
	}
	while (node->next)
	{
		node = node->next;
		++index;
	}
	return (index + 1);
}
int	price_to_push_this(t_stack **list, int value, t_all *all)
{
	t_stack	*node;
	int		size;
	int		price;
	int		pos;

	pos = 0;
	size = 0;
	price = 0;
	node = *list;
	while (node->next && node->data != value)
	{
		node = node->next;
		++size;
	}
	

}
void	presort(t_all *all)
{
	print_list(all->pile_a);
	// push_this(&all->pile_a, 2, all);
	print_list(all->pile_a);
	print_list(all->pile_b);
}
