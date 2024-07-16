/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:33:19 by mdembele          #+#    #+#             */
/*   Updated: 2024/07/16 20:17:03 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_double(int n, t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (false);
	temp = stack;
	while (temp)
	{
		if (n == temp->data)
			return (true);
		temp = temp->next;
	}
	return (false);
}

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
	t_stack	*save;

	free((all->i = 0, all->j = 0, save = (*list), NULL));
	all->tab_char_numbers = ft_split(av, 32);
	if (verif_numbers(all->tab_char_numbers) == -1)
		free_and_exit("Error", EXIT_FAILURE, all);
	while (all->tab_char_numbers[all->i])
		all->i++;
	all->tab_int_numbers = ft_calloc(sizeof(long long), all->i);
	all->i = 0;
	while (all->tab_char_numbers[all->i])
	{
		all->tab_int_numbers[all->i] = ft_atoi(all->tab_char_numbers[all->i]);
		all->i++;
	}
	while (all->i-- > 0)
	{
		if (is_double(all->tab_int_numbers[all->j], *list)
			|| all->tab_int_numbers[all->j] > INT_MAX
			|| all->tab_int_numbers[all->j] < INT_MIN)
			free_and_exit("Error", EXIT_FAILURE, all);
		save = create_node(all->tab_int_numbers[all->j], all->j);
		ft_stack_back(list, save);
		all->j++;
	}
}

void	multi_parse(char **av, t_all *all)
{
	int		count;
	t_stack	*save;
	int		j;

	free((all->i = 0, j = 0, count = 0, av = av + 1, NULL));
	if (verif_numbers(av) == -1)
		free_and_exit("Error", EXIT_FAILURE, all);
	while (av[count])
		count++;
	all->tab_int_numbers = ft_calloc(sizeof(long long), count);
	while (av[all->i])
	{
		all->tab_int_numbers[all->i] = ft_atoi(av[all->i]);
		all->i++;
	}
	while (all->i > 0)
	{
		if (is_double(all->tab_int_numbers[j], all->pile_a)
			|| all->tab_int_numbers[j] > INT_MAX
			|| all->tab_int_numbers[j] < INT_MIN)
			free_and_exit("Error", EXIT_FAILURE, all);
		save = create_node(all->tab_int_numbers[j], j);
		ft_stack_back(&all->pile_a, save);
		free((j++, all->i--, NULL));
	}
}
