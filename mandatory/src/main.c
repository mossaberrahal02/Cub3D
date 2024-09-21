#include "cub3d.h"





void	print_full_map(t_all *all)
{
	int	i;

	i = 0;
	/* TODO this function should be removed */
	while (all->full_map[i])
	{
		printf("%s", all->full_map[i]);
		i++;
	}
}

void	parsing(t_all *all, int ac, char **av)
{
	all->ac = ac;
	all->av = av;
	fetch_full_map(all);
	// print_full_map(all);
}

int	main(int ac, char **av)
{
	t_all	*all;

	all = ft_calloc(1, sizeof(t_all));
	if (ac != 2)
		return (ft_putstr_fd("bad arguments\n", 2), 1);
	parsing(all, ac, av);
}
