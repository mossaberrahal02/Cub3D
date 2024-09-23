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
	// printf("ggggggggggg{%s}\n", all->full_map);
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

int isnt_valid(char *splitted, t_texture *tmp)
{
	//TODO they should not be dupplicated
	if(strncmp(splitted, "NO", 3) == 0)
		tmp->no_count++;
	else if(strncmp(splitted, "SO", 3) == 0)
		tmp->so_count++;
	else if(strncmp(splitted, "WE", 3) == 0)
		tmp->we_count++;
	else if(strncmp(splitted, "EA", 3) == 0)
		tmp->ea_count++;
	else if(strncmp(splitted, "F", 2) == 0)
		tmp->f_count++;
	else if(strncmp(splitted, "C", 2) == 0)
		tmp->c_count++;
	else
		return FAILURE;
	return SUCCESS;
}

int	parse_textures_colors(t_all *all)
{
	int	i;
	t_texture tmp;
	char **splitted;

	i = 0;
	ft_bzero(&tmp, sizeof(t_texture));
	while (all->full_map[i] && i < 6)
	{
		splitted = ft_split_multi(all->full_map[i], " \t");
		if(isnt_valid(splitted[0], &tmp) == FAILURE)
			return (ft_putstr_fd("Error: in textures or collors\n", 2), FAILURE);
		i++;
	}
	// 		printf("2)no_count{%d} so_count{%d} we_count{%d} \
	// 			ea_count{%d} f_count{%d} c_count{%d}\n",
	// tmp.no_count,
	// tmp.so_count,
	// tmp.we_count,
	// tmp.ea_count,
	// tmp.f_count,
	// tmp.c_count);
	if(tmp.f_count == 0 || tmp.c_count == 0 || tmp.no_count == 0 || tmp.so_count == 0 || tmp.we_count == 0
	|| tmp.ea_count == 0 || tmp.no_count > 1 || tmp.so_count > 1
	|| tmp.we_count > 1 || tmp.ea_count > 1 || tmp.f_count > 1 || tmp.c_count > 1)
		return (ft_putstr_fd("Error: dupplicates\n", 2), FAILURE);
	return (ft_putstr_fd("textures and collors are good\n", 2), SUCCESS);
}

int	check_full_map_content(t_all *all)
{
	if (!has_more_than_six_lines(all))
		return (ft_putstr_fd("Error : map has less than 6 lines\n", 2), FAILURE);
	// full_map_print(all);
	if (parse_textures_colors(all) == FAILURE)
		return (FAILURE);
	return (ft_putstr_fd("map has more then 6 lines\n", 2), SUCCESS);
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
	printf("recources been freed end of programme\n");
}
