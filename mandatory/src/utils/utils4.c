#include "cub3d.h"

void	ft_open(t_all *all, char **xpm_file)
{
	if (open(xpm_file[1], O_RDONLY) == -1)
	{
		perror("open");
		ft_putstr_fd(xpm_file[1], 2);
		ft_putstr_fd("\n", 2);
		_free();
		exit(1);
	}
	if (!ft_strncmp(xpm_file[0], "NO", 3))
		all->textures.no = xpm_file[1];
	else if (!ft_strncmp(xpm_file[0], "SO", 3))
		all->textures.so = xpm_file[1];
	else if (!ft_strncmp(xpm_file[0], "EA", 3))
		all->textures.ea = xpm_file[1];
	else if (!ft_strncmp(xpm_file[0], "WE", 3))
		all->textures.we = xpm_file[1];
}

int	ft_isspace(char *to_check)
{
	int	i;

	i = 0;
	while (to_check[i])
	{
		if (to_check[i] != ' ' && to_check[i] != '\t' && to_check[i] != '\n')
			return (2);
		i++;
	}
	return (3);
}

int	count(char **to_count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (to_count[i])
	{
		if (ft_isspace(to_count[i]) == 3)
		{
			i++;
			continue ;
		}
		j++;
		i++;
	}
	return (j);
}

int	check_comma(t_all *all)
{
	int		i;
	char	*tmp;
	char	**splitted;

	i = 0;
	while (all->full_map[i] && i < 6)
	{
		if (!ft_strncmp(&all->full_map[i][0], "F", 1)
			|| !ft_strncmp(&all->full_map[i][0], "C", 1))
		{
			tmp = ft_substr(all->full_map[i], 1, ft_strlen(all->full_map[i]));
			gc_push(tmp);
			splitted = ft_split_multi(tmp, ",");
			if (count(splitted) != 3)
				return (ft_putstr_fd(RED "Error : more or less then\
					3\n" ENDC, 2), FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int	check_full_map_content(t_all *all)
{
	if (!has_more_than_six_lines(all))
		return (ft_putstr_fd(RED "Error : map has less than 6 lines\n" ENDC, 2),
			FAILURE);
	if (parse_textures_colors(all) == FAILURE)
		return (FAILURE);
	if (parse_mini_map(all) == FAILURE)
		return (FAILURE);
	if (check_white_space_in_the_mini_map(all) == FAILURE)
		return (FAILURE);
	if (check_comma(all) == FAILURE)
		return (FAILURE);
	if (parse_f_c(all) == FAILURE)
		return (FAILURE);
	set_player_direction(all);
	return (SUCCESS);
}
