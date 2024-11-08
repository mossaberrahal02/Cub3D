/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:22:29 by merrahal          #+#    #+#             */
/*   Updated: 2024/11/08 16:22:50 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	full_map_print(t_all *all)
// {
// 	int	i;

// 	i = 0;
// 	/* TODO this function should be removed */
// 	if (!all->full_map2)
// 		return ;
// 	printf("printing full map\n");
// 	while (all->full_map2[i])
// 	{
// 		printf("{%s}\n", all->full_map2[i]);
// 		i++;
// 	}
// }

int	check_white_space_in_the_mini_map(t_all *all)
{
	int		i;
	int		tmp_first_line_mini_map;
	char	*trimmed;
	char	*trimmed2;
	size_t	j;

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
	tmp_first_line_mini_map = i;
	while (all->full_map2[i + 1])
	{
		all->mini_map_height++;
		trimmed = ft_strtrim(all->full_map2[i], " \t");
		trimmed2 = ft_strtrim(all->full_map2[i + 1], " \t");
		(gc_push(trimmed), gc_push(trimmed2));
		if (trimmed[0] == '\0' && trimmed2[0] != '\0')
			return (ft_putstr_fd(RED "Error : nl in the mini map\n" ENDC, 2),
				FAILURE);
		i++;
	}
	i = tmp_first_line_mini_map;
	while (all->full_map2[i])
	{
		if (ft_strlen(all->full_map2[i]) > all->mini_map_width)
			all->mini_map_width = ft_strlen(all->full_map2[i]);
		i++;
	}
	i = tmp_first_line_mini_map;
	j = 0;
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
	// fill the reste of the lines with spaces so i can
	// check later if there is space
	while (all->two_d_map[i])
	{
		j = 0;
		while (j < all->mini_map_width)
		{
			if (all->two_d_map[i][j] == '\0')
				all->two_d_map[i][j] = ' ';
			j++;
		}
		i++;
	}
	i = 0;
	while (all->two_d_map[i])
	{
		j = 0;
		while (j < all->mini_map_width)
		{
			if ((all->two_d_map[i][j] == '0' || all->two_d_map[i][j] == 'N'
					|| all->two_d_map[i][j] == 'E'
					|| all->two_d_map[i][j] == 'W'
					|| all->two_d_map[i][j] == 's') &&
				(all->two_d_map[i - 1][j] == ' ' || all->two_d_map[i
						+ 1][j] == ' ' ||
					all->two_d_map[i][j - 1] == ' ' || all->two_d_map[i][j
						+ 1] == ' ' ||
					all->two_d_map[i - 1][j] == '\t' || all->two_d_map[i
						+ 1][j] == '\t' ||
					all->two_d_map[i][j - 1] == '\t' || all->two_d_map[i][j
						+ 1] == '\t'))
				return (ft_putstr_fd(RED "Error : 0 wla Player acces\
						empty space\n" ENDC, 2), FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
//TODO texture files should be valide end with .xpm

int	parse_f_c(t_all *all)
{
	int	i;

	i = 0;
	char **(splitted), **(splitted2);
	while (all->full_map[i] && i < 6)
	{
		splitted2 = ft_split_multi(all->full_map[i], " \t");
		if (!ft_strncmp(splitted2[0], "NO", 3) || !ft_strncmp(splitted2[0],
				"SO", 3) || !ft_strncmp(splitted2[0], "EA", 3)
			|| !ft_strncmp(splitted2[0], "WE", 3))
		{
			if (finish_with_xpm(splitted2[1]) == FAILURE)
				return (ft_putstr_fd(RED "Error: bad extension\
				(.xpm)\n" ENDC, 2), FAILURE);
			ft_open(all, splitted2);
		}
		if (!ft_strncmp(splitted2[0], "F", 2) || !ft_strncmp(splitted2[0], "C",
				2))
		{
			if (count_q(all, splitted2) == FAILURE)
				return (FAILURE);
		}
		splitted = ft_split_multi(all->full_map[i], " \t,");
		if (!ft_strncmp(splitted[0], "F", 2) || !ft_strncmp(splitted[0], "C",
				2))
		{
			if (f_c_are_valid(all, splitted) == FAILURE)
				return (FAILURE);
		}
		i++;
	}
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
		return (_free(), ft_putstr_fd(RED "Error : bad arguments\n" ENDC, 2),
			FAILURE);
	parsing(all, ac, av);
	printf("mini_map_width = %zu\n", all->mini_map_width);
	printf("mini_map_height = %zu\n", all->mini_map_height);
	printf("all->player.dir_x = %d\n", all->player.dir_x);
	printf("all->player.dir_y = %d\n", all->player.dir_y);
	printf("all->player.row = %d\n", all->player.row);
	printf("all->player.column = %d\n", all->player.column);
	printf("all->player.no = %s\n", all->textures.no);
	printf("all->player.so = %s\n", all->textures.so);
	printf("all->player.ea = %s\n", all->textures.ea);
	printf("all->player.we = %s\n", all->textures.we);

	_free();
}
//TODO check every texture file if its empty or not i think its gonna segv