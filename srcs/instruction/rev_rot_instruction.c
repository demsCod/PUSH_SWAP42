/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:46:23 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/16 20:04:03 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack **liste)
{
	t_stack	*restore;
	int		size;

	restore = (*liste);
	size = ft_stacksize(*liste) - 1;
	if (size < 1)
		return ;
	(*liste) = restore;
	while (size != 0)
	{
		size--;
		rotate(liste);
	}
}

void	reverse_rotate_b(t_all *all)
{
	reverse_rotate(&all->pile_b);
	ft_putendl_fd("rrb", 1);
}

void	reverse_rotate_a(t_all *all)
{
	reverse_rotate(&all->pile_a);
	ft_putendl_fd("rra", 1);
}

void	rev_rot_rot(t_all *all)
{
	reverse_rotate(&all->pile_a);
	reverse_rotate(&all->pile_b);
	ft_putendl_fd("rrr", 1);
}
