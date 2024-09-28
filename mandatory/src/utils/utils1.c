#include "cub3d.h"

void	ft_close(int fd)
{
	if (close(fd) == -1)
		return (_free(), ft_putstr_fd("Error : ft_close()\n", 2), exit(1));
}

int	count_mapfile_height(t_all *all)
{
	char	*line;
	int		fd;
	size_t		i;

	fd = open(all->av[1], O_RDONLY);
	i = 0;
	if (fd < 0)
		return (ft_putstr_fd(RED"Error : mapfile\n"ENDC, 2), 1);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		gc_push(line);
		line = get_next_line(fd);
	}
	ft_close(fd);
	return (i);
}

int	check_file_extention(t_all *all)
{
	size_t	len;

	len = ft_strlen(all->av[1]);
	if (ft_strncmp(((all->av[1]) + (len - 4)), ".cub", 4))
		return (ft_putstr_fd(RED"Error : bad extention\n"ENDC, 2), FAILURE);
	return (SUCCESS);
}

int	fetch_full_map(t_all *all)
{
	int		i;
	char	*line;

	i = 0;
	if (check_file_extention(all))
		return (FAILURE);
	all->height_full_map = count_mapfile_height(all);
	all->fd = open(all->av[1], O_RDONLY);
	if (all->fd < 0)
		return (ft_putstr_fd(RED"Error : error with mapfile\n"ENDC, 2), FAILURE);
	all->full_map = ft_calloc((all->height_full_map + 1), sizeof(char *));
	all->full_map2 = ft_calloc((all->height_full_map + 1), sizeof(char *));
	(gc_push(all->full_map), gc_push(all->full_map2));
	line = get_next_line(all->fd);
	while (line)
	{
		gc_push(line);
		if (ft_strchr(line, '\n'))
			line[ft_strlen(line) - 1] = '\0';
		all->full_map[i] = line;
		all->full_map2[i] = line;
		i++;
		line = get_next_line(all->fd);
	}
	return (ft_close(all->fd), SUCCESS);
}
