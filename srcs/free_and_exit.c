/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:48:30 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/14 19:53:27 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_err_and_exit(const char *err, int code)
{
	if (status == true)
	{
		perror((char *)err);
		exit(code);
	}
	if (err != NULL)
	{
		ft_putendl_fd((char *)err, STDERR_FILENO);
	}
	exit(code);
}
void ft_free_nodes(t_stack **node)
{
	t_stack *next_node;
	if(!*node)
		return;
	while(*node)
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
	ft_free((void **)&x);
	if(err)
		ft_putendl_fd(err, 2);
	exit(code);
}