#include "push_swap.h"

void ft_free_nodes(t_stack **node)
{
	t_stack *next_node;
	while(*node)
	{
		next_node = (*node)->next;
		free(*node);
		*node = next_node;
	}
}

int	main(int ac, char **av)
{
	t_all *all;

	all = malloc(sizeof(t_all));
	ft_bzero(all, sizeof(t_all));
	if (ac >= 2)
	{
		if (ac == 2)
			parse_args(av[1], &all->pile_a, all);
		else
			multi_parse(av, all);
		if (list_is_sorted(&all->pile_a) == 0)
			{
				ft_free_nodes(&all->pile_a);
				free(all);
				exit(0);	
			}
		else
		{
			if (ft_stacksize(all->pile_a) <= 3)
				tiny_sort(&all->pile_a, all);
			sorting_list(all);
			ft_free_nodes(&all->pile_a);
			free(all);
		}
	}
}