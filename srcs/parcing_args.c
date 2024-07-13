/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:33:19 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/12 18:04:40 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_command(char **av)
{
	size_t	i;
	char	*comand;

	i = 1;
	while (av[i] != NULL)
	{
		comand = ft_strjoin(comand, av[i]);
		comand = ft_strjoin(comand, " ");
		if (!(av[i]))
		{
			ft_free_2d((void ***)av);
			return (NULL);
		}
		i++;
	}
	return (comand);
}

int	verif_numbers(char **str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (!(str[j][i] >= '0' && str[j][i] <= '9') && str[j][i] != '-')
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

void	parse_args(char *av, t_stack **list, t_all *all)
{
	char	**tab_char_numbers;
	int		*tab_int_numbers;
	int		count;
	int		j;
	t_stack	*save;
	int		i;

	i = 0;
	count = 0;
	j = 0;
	save = (*list);
	tab_char_numbers = ft_split(av, 32);
	if (verif_numbers(tab_char_numbers) == -1)
		exit(EXIT_FAILURE);
	while (tab_char_numbers[count])
		count++;
	tab_int_numbers = calloc(sizeof(int), count);
	while (tab_char_numbers[i])
	{
		tab_int_numbers[i] = ft_atoi(tab_char_numbers[i]);
		i++;
	}
	while (i != 0)
	{
		save = create_node(tab_int_numbers[j], j);
		ft_stack_back(list, save);
		j++;
		i--;
	}
	all->n_numbers = i;
}
