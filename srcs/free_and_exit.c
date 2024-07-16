/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:48:30 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/16 20:05:00 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_nodes(t_stack **node)
{
	t_stack	*next_node;

	if (!*node)
		return ;
	while (*node)
	{
		next_node = (*node)->next;
		free(*node);
		*node = next_node;
	}
}

void	free_and_exit(const char *err, int code, t_all *x)
{
	ft_free_nodes(&x->pile_a);
	ft_free_nodes(&x->pile_b);
	ft_free((void **)&x->tab_int_numbers);
	ft_free_2d((void ***)&x->tab_char_numbers);
	ft_free((void **)&x);
	if (err)
		ft_putendl_fd((char *)err, 2);
	exit(code);
}
