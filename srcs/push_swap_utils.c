/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:54:15 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/14 21:30:36 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *lst);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
int	ft_stacksize(t_stack *lst);

t_stack	*create_node(int data, int index)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	new_node->data = data;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*last_node(t_stack **lst)
{
	if ((*lst) == NULL)
		return (0);
	while ((*lst)->next != NULL)
	{
		if ((*lst)->next == NULL)
			return ((*lst));
		(*lst) = (*lst)->next;
	}
	return ((*lst));
}

void	print_list(t_stack *list)
{
	while (list)
	{
		printf("[%d]->", list->data);
		list = list->next;
	}
	printf("NULL\n");
}

int list_is_sorted(t_stack **list)
{
	t_stack *save;

	save = (*list);
	if (save)
	while(save->next != NULL)
	{
		if (save->next->data < save->data)
			return(	EXIT_FAILURE);
		save = save->next;
	}
	return (EXIT_SUCCESS);
}

void tiny_sort (t_stack **list, t_all *all)
{
	if ((*list)->data > (*list)->next->data)
		ft_swap_a(all);
	if ((*list)->next->next)
	{
		if ((*list)->next->next->data < (*list)->next->data)
			reverse_rotate_a(all);
	}
	if ((*list)->data > (*list)->next->data)
		ft_swap_a(all);
}