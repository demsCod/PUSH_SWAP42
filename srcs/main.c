/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:56:09 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/16 19:56:14 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_all	*all;

	if (ac >= 2)
	{
		all = malloc(sizeof(t_all));
		ft_bzero(all, sizeof(t_all));
		if (ac == 2)
			parse_args(av[1], &all->pile_a, all);
		else
			multi_parse(av, all);
		if (list_is_sorted(&all->pile_a) == 0)
			free_and_exit(NULL, EXIT_SUCCESS, all);
		else
		{
			if (ft_stacksize(all->pile_a) <= 3)
				tiny_sort(&all->pile_a, all);
			sorting_list(all);
			free_and_exit(NULL, EXIT_SUCCESS, all);
		}
	}
}
