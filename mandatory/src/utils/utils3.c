#include "cub3d.h"

int	parse_mini_map(t_all *all)
{
	int	i;

	i = 6;
	if (has_only_ones(all->full_map[i++]) == FAILURE)
		return (ft_putstr_fd(RED "Error : first line\n" ENDC, 2), FAILURE);
	while (all->full_map[i])
	{
		if (start_end_with_one(all, all->full_map[i]))
			return (FAILURE);
		i++;
	}
	i--;
	if (has_only_ones(all->full_map[i]) == FAILURE)
		return (ft_putstr_fd(RED "Error : last line\n" ENDC, 2), FAILURE);
	if (all->p_count != 1)
		return (ft_putstr_fd(RED "Error: nbr of player\n" ENDC, 2), FAILURE);
	return (/* ft_putstr_fd(YELLOW"good map\n"ENDC, 2),  */ SUCCESS);
}

void	convert_rgb(t_all *all, char **splitted, char c)
{
	if (c == 'C')
	{
		all->c.r = ft_atoi(splitted[1]);
		all->c.g = ft_atoi(splitted[2]);
		all->c.b = ft_atoi(splitted[3]);
	}
	else if (c == 'F')
	{
		all->f.r = ft_atoi(splitted[1]);
		all->f.g = ft_atoi(splitted[2]);
		all->f.b = ft_atoi(splitted[3]);
	}
}

int	f_c_are_valid(t_all *all, char **splitted)
{
	int	len;

	len = 0;
	while (splitted[len])
		len++;
	if (len != 4)
	{
		printf(RED "Error: %s not valid\n" ENDC, splitted[0]);
		return (FAILURE);
	}
	convert_rgb(all, splitted, splitted[0][0]);
	return (SUCCESS);
}

int	count_q(t_all *all, char **splitted)
{
	int	i;
	int	j;
	int	q;

	(void)all;
	i = 1;
	j = 0;
	q = 0;
	while (splitted[i])
	{
		j = 0;
		while (splitted[i][j])
		{
			if (splitted[i][j] == ',')
				q++;
			j++;
		}
		i++;
	}
	if (q != 2)
		return (ft_putstr_fd(RED "Error : a lot of ','\n" ENDC, 2), FAILURE);
	return (SUCCESS);
}

int	finish_with_xpm(char *to_check_xpm)
{
	int	len;

	len = 0;
	while (to_check_xpm[len])
		len++;
	if (ft_strncmp(((to_check_xpm) + (len - 4)), ".xpm", 4))
		return (FAILURE);
	return (SUCCESS);
}
