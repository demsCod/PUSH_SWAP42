/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:33:56 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/12 20:35:00 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_all *all, size_t numbers)
{
	while (numbers--)
	{
		reverse_rotate_a(all);
	}
}
void	ra(t_all *all, size_t numbers)
{
	while (numbers--)
	{
		rotate_a(all);
	}
}

void	rrb(t_all *all, size_t numbers)
{
	while (numbers--)
	{
		reverse_rotate_b(all);
	}
}
void	rb(t_all *all, size_t numbers)
{
	while (numbers--)
	{
		rotate_b(all);
	}
}
