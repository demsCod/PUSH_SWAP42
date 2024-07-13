#include "push_swap.h"

int	main(int ac, char **av)
{
	t_all *all;

	all = malloc(sizeof(t_all));
	ft_bzero(all, sizeof(t_all));
	if (ac == 2)
	{
		parse_args(av[1], &all->pile_a, all);
		if (list_is_sorted(&all->pile_a) == 0)
			printf("is sorted\n");
		else
		{
			if (all->n_numbers <= 3)
				tiny_sort(&all->pile_a, all);
			sorting_list(all);
		}
	}
}