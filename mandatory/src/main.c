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

int has_more_then_six_lines(t_all *all)
{
	int		i;
	int		j;
	char	*trimmed;

	i = 0;
	j = 0;
	while (all->full_map[i])
	{
		trimmed = ft_strtrim(all->full_map[i], " \t");
		if(trimmed[0] != '\0')
			j++;
		free(trimmed);
		i++;
	}
	return (j >= 6);
}

int 	check_full_map_content(t_all *all)
{
	if(!has_more_then_six_lines(all))
		return (ft_putstr_fd("Error : map has less than 6 lines\n", 2), 1);
	return (ft_putstr_fd("hta l daba mlih\n", 2), 0);
}

void	parsing(t_all *all, int ac, char **av)
{
	all->ac = ac;
	all->av = av;
	fetch_full_map(all);
	check_full_map_content(all);
}

int	main(int ac, char **av)
{
	t_all	*all;

	all = ft_calloc(1, sizeof(t_all));
	if (ac != 2)
		return (ft_putstr_fd("Error : bad arguments\n", 2), 1);
	parsing(all, ac, av);
}
