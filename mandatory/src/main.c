#include "cub3d.h"

void	full_map_print(t_all *all)
{
	int	i;

	i = 0;
	/* TODO this function should be removed */
	while (all->full_map[i])
	{
		printf("{%s}\n", all->full_map[i]);
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
	//TODO they should not be dupplicated
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
			return (ft_putstr_fd("Error: in textures or collors\n", 2),
				FAILURE);
		i++;
	}
	if (tmp.f_count == 0 || tmp.c_count == 0 || tmp.no_count == 0
		|| tmp.so_count == 0 || tmp.we_count == 0 || tmp.ea_count == 0
		|| tmp.no_count > 1 || tmp.so_count > 1 || tmp.we_count > 1
		|| tmp.ea_count > 1 || tmp.f_count > 1 || tmp.c_count > 1)
		return (ft_putstr_fd("Error: dupplicates\n", 2), FAILURE);
	return (ft_putstr_fd("textures and collors are good\n", 2), SUCCESS);
}

int	has_only_ones(char *line, int *current_line_len)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '1')
			return (FAILURE);
		i++;
	}
	if (current_line_len)
		*current_line_len = i;
	return (SUCCESS);
}

int	is_player(t_all *all, char *line, int i)
{
	//TODO initialize the player count to 0
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
	{
		all->p_count++;
		if (all->p_count != 1)
			return (ft_putstr_fd("Error: Many players\n", 2), FAILURE);
	}
	if ((line[i] == '0' && line[i + 1] == ' ')
		|| (line[i] == '0' && line[i + 1] == '\t')
		|| (line[i] == '0' && line[i - 1] == ' ')
		|| (line[i] == '0' && line[i - 1] == '\t'))
		return (ft_putstr_fd("Error: invalid map 0 hdaha space\n", 2), FAILURE);
	return (SUCCESS);
}

int	start_end_with_one(t_all *all, char *line, int *current_line_len)
{
	int	i;

	i = 1;
	all->p_count = 0;
	if (line[0] != '1')
		return (ft_putstr_fd("Error : begining dyal chi line in the middel of the mini map\n",2), FAILURE);
	while (line[i])
	{
		if (is_player(all, line, i))
			return (FAILURE);
		if (line[i] != ' ' && line[i] != '1'
			&& line[i] != '\t' && line[i] != '0'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != 'D')
			return (ft_putstr_fd("Error : wrong character\n", 2), FAILURE);
		i++;
	}
	if (current_line_len)
		*current_line_len = i;
	i--;
	if (line[i] != '1')
	{
		printf("wrong character [%c] in line (%s) \n", line[i], line);
		return (ft_putstr_fd("Error : ending dyal chi line in the middel of the mini map\n", 2),
				FAILURE);
	}
	return (SUCCESS);
}

int	parse_mini_map(t_all *all)
{
	int	i;
	int	j;
	int	first_line_len;
	int	last_line_len;
	int	current_line_len;

	first_line_len = 0;
	last_line_len = 0;
	current_line_len = 0;
	j = 0;
	i = 6;
	if (has_only_ones(all->full_map[i++], &first_line_len) == FAILURE)
	{
		return (ft_putstr_fd("Error : first line\n", 2), FAILURE);
	}
	printf("first_line_len = %d\n", first_line_len);
	while (all->full_map[i])
	{
		printf("i = %d\n", i);
		if (start_end_with_one(all, all->full_map[i], &current_line_len))
		{

			return (FAILURE);
		}

		i++;
		printf("current_line_len= [%d]\n", current_line_len);
	}
	i--;
	if (has_only_ones(all->full_map[i], &last_line_len) == FAILURE)
	{
		return (ft_putstr_fd("Error : last line\n", 2), FAILURE);
	}
	printf("last_line_len = %d\n", last_line_len);
	return (ft_putstr_fd("good map\n", 2), SUCCESS);
}

int	check_full_map_content(t_all *all)
{
	if (!has_more_than_six_lines(all))
		return (ft_putstr_fd("Error : map has less than 6 lines\n", 2),
			FAILURE);
	if (parse_textures_colors(all) == FAILURE)
		return (FAILURE);
	if (parse_mini_map(all) == FAILURE)
		return (FAILURE);
	// full_map_print(all);
	return (SUCCESS);
}

int	parsing(t_all *all, int ac, char **av)
{
	all->ac = ac;
	all->av = av;
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
		return (_free(), ft_putstr_fd("Error : bad arguments\n", 2), FAILURE);
	parsing(all, ac, av);
	_free();
	printf("end of program\n");
}
