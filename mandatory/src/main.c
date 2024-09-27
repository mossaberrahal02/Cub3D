#include "cub3d.h"

void	full_map_print(t_all *all)
{
	int	i;

	i = 0;
	/* TODO this function should be removed */
	if (!all->full_map2)
		return ;
	printf("printing full map\n");
	while (all->full_map2[i])
	{
		printf("{%s}\n", all->full_map2[i]);
		i++;
	}
}

int	has_more_than_six_lines(t_all *all)
{
	int		i;
	int		j;
	int		k;
	char	*trimmed;

	i = 0;
	j = 0;
	k = 0;
	while (all->full_map[i])
	{
		trimmed = ft_strtrim(all->full_map[i], " \t");
		if (trimmed[0] != '\0')
		{
			j++;
			all->full_map[k++] = trimmed;
		}
		gc_push(trimmed);
		i++;
	}
	all->full_map[k] = NULL;
	return (j > 6);
}

int	isnt_valid(char *splitted, t_texture *tmp)
{
	if (strncmp(splitted, "NO", 3) == 0)
		tmp->no_count++;
	else if (strncmp(splitted, "SO", 3) == 0)
		tmp->so_count++;
	else if (strncmp(splitted, "WE", 3) == 0)
		tmp->we_count++;
	else if (strncmp(splitted, "EA", 3) == 0)
		tmp->ea_count++;
	else if (strncmp(splitted, "F", 2) == 0)
		tmp->f_count++;
	else if (strncmp(splitted, "C", 2) == 0)
		tmp->c_count++;
	else
		return (FAILURE);
	return (SUCCESS);
}

int	parse_textures_colors(t_all *all)
{
	int			i;
	t_texture	tmp;
	char		**splitted;

	i = 0;
	ft_bzero(&tmp, sizeof(t_texture));
	while (all->full_map[i] && i < 6)
	{
		splitted = ft_split_multi(all->full_map[i], " \t");
		if (isnt_valid(splitted[0], &tmp) == FAILURE)
			return (ft_putstr_fd(RED"Error: in textures or collors\n"ENDC, 2),
					FAILURE);
		i++;
	}
	if (tmp.f_count == 0 || tmp.c_count == 0 || tmp.no_count == 0
		|| tmp.so_count == 0 || tmp.we_count == 0 || tmp.ea_count == 0
		|| tmp.no_count > 1 || tmp.so_count > 1 || tmp.we_count > 1
		|| tmp.ea_count > 1 || tmp.f_count > 1 || tmp.c_count > 1)
		return (ft_putstr_fd(RED"Error: dupplicates\n"ENDC, 2), FAILURE);
	return (ft_putstr_fd("textures and collors are good\n", 2), SUCCESS);
}

int	has_only_ones(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	is_player(t_all *all, char *line, int i)
{
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		all->p_count++;
	if ((line[i] == '0' && line[i + 1] == ' ') || (line[i] == '0' && line[i
			+ 1] == '\t') || (line[i] == '0' && line[i - 1] == ' ')
		|| (line[i] == '0' && line[i - 1] == '\t'))
		return (ft_putstr_fd(RED"Error: invalid map 0 hdaha space\n"ENDC, 2), FAILURE);
	return (SUCCESS);
}

int	start_end_with_one(t_all *all, char *line)
{
	int	i;

	i = 1;
	if (line[0] != '1')
		return (ft_putstr_fd(RED"Error : begining dyal chi line in the middel of the mini map\n"ENDC,
				2), FAILURE);
	while (line[i])
	{
		if (is_player(all, line, i))
			return (FAILURE);
		if (line[i] != ' ' && line[i] != '1' && line[i] != '\t'
			&& line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != 'D')
			return (ft_putstr_fd(RED"Error : wrong character\n"ENDC, 2), FAILURE);
		i++;
	}
	i--;
	if (line[i] != '1')
		return (ft_putstr_fd(RED"Error : ending dyal chi line in the middel of the mini map\n"ENDC,
				2), FAILURE);
	return (SUCCESS);
}

int	parse_mini_map(t_all *all)
{
	int	i;
	int	j;

	j = 0;
	i = 6;
	if (has_only_ones(all->full_map[i++]) == FAILURE)
		return (ft_putstr_fd(RED"Error : first line\n"ENDC, 2), FAILURE);
	while (all->full_map[i])
	{
		if (start_end_with_one(all, all->full_map[i]))
			return (FAILURE);
		i++;
	}
	i--;
	if (has_only_ones(all->full_map[i]) == FAILURE)
		return (ft_putstr_fd(RED"Error : last line\n"ENDC, 2), FAILURE);
	if (all->p_count != 1)
		return (ft_putstr_fd(RED"Error: nbr of player\n"ENDC, 2), FAILURE);
	return (ft_putstr_fd(YELLOW"good map\n"ENDC, 2), SUCCESS);
}

int	check_white_space_in_the_mini_map(t_all *all)
{
	int		i;
	int		tmp;
	char	*trimmed;
	char	*trimmed2;
	all->mini_map_height = 1;
	all->mini_map_width = 1;

	i = 0;
	while (all->full_map2[i])
	{
		trimmed = ft_strtrim(all->full_map2[i], " \t");
		gc_push(trimmed);
		if (!ft_strncmp(trimmed, all->full_map[6], ft_strlen(all->full_map[6])))
			break ;
		i++;
	}
	tmp = i;
	while (all->full_map2[i + 1])
	{
		all->mini_map_height++;
		trimmed = ft_strtrim(all->full_map2[i], " \t");
		trimmed2 = ft_strtrim(all->full_map2[i + 1], " \t");
		(gc_push(trimmed), gc_push(trimmed2));
		if (trimmed[0] == '\0' && trimmed2[0] != '\0')
			return (ft_putstr_fd(RED"Error : nl in the mini map\n"ENDC, 2), FAILURE);
		i++;
	}
	i = tmp;
	while (all->full_map2[i])
	{
		if (ft_strlen(all->full_map2[i]) > all->mini_map_width)
			all->mini_map_width = ft_strlen(all->full_map2[i]);
		i++;
	}
	i = tmp;
	size_t j = 0;
	all->two_d_map = ft_calloc((all->mini_map_height + 1), sizeof(char *));
	all->two_d_map[all->mini_map_height] = NULL;
	gc_push(all->two_d_map);
	while (all->full_map2[i])
	{
		all->two_d_map[j] = ft_calloc((all->mini_map_width + 1), sizeof(char));
		gc_push(all->two_d_map[j]);
		ft_strcpy(all->two_d_map[j], all->full_map2[i]);
		i++;
		j++;
	}
	i = 0;
	while (all->two_d_map[i])
	{
		j = 0;
		while (j < all->mini_map_width)
		{
			if(all->two_d_map[i][j] == '\0')
				all->two_d_map[i][j] = ' ';
			j++;
		}	
		i++;
	}
	i=0;
	while (all->two_d_map[i])
	{
		j = 0;
		while (j < all->mini_map_width)
		{
			if(all->two_d_map[i][j] == '0'
			&&
			(
				all->two_d_map[i - 1][j] == ' ' || all->two_d_map[i + 1][j] == ' '
				||
				all->two_d_map[i][j - 1] == ' ' || all->two_d_map[i][j + 1] == ' '
				||
				all->two_d_map[i - 1][j] == '\t' || all->two_d_map[i + 1][j] == '\t'
				||
				all->two_d_map[i][j - 1] == '\t' || all->two_d_map[i][j + 1] == '\t'
			))
			return (ft_putstr_fd(RED"Error : 0 hdaha empty space\n"ENDC, 2), FAILURE);
			j++;
		}	
		i++;
	}
	return (SUCCESS);
}

int	check_full_map_content(t_all *all)
{
	if (!has_more_than_six_lines(all))
		return (ft_putstr_fd(RED"Error : map has less than 6 lines\n"ENDC, 2),
			FAILURE);
	if (parse_textures_colors(all) == FAILURE)
		return (FAILURE);
	if (parse_mini_map(all) == FAILURE)
		return (FAILURE);
	if (check_white_space_in_the_mini_map(all) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	parsing(t_all *all, int ac, char **av)
{
	all->ac = ac;
	all->av = av;
	all->p_count = 0;
	if (fetch_full_map(all))
		return (FAILURE);
	if (check_full_map_content(all))
		return (FAILURE);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_all	*all;

	all = ft_calloc(1, sizeof(t_all));
	gc_push(all);
	if (ac != 2)
		return (_free(), ft_putstr_fd(RED"Error : bad arguments\n"ENDC, 2), FAILURE);
	parsing(all, ac, av);
	// full_map_print(all);
	_free();
	printf("end of program\n");
}
