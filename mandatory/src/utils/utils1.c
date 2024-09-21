#include "cub3d.h"

void	ft_close(int fd)
{
	if (close(fd) == -1)
	{
		// TODO free what should be freed
		return (ft_putstr_fd("Error : ft_close()\n", 2), exit(1));
	}
}

int	count_mapfile_height(t_all *all)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(all->av[1], O_RDONLY);
	i = 0;
	if (fd < 0)
		return (ft_putstr_fd("Error : mapfile\n", 2), exit(1), 1);
	(line = get_next_line(fd));
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	ft_close(fd);
	return (i);
}

void	check_file_extention(t_all *all)
{
	int	len;

	len = 0;
	len = ft_strlen(all->av[1]);
	if (ft_strncmp(((all->av[1]) + (len - 4)), ".cub", 4))
		return (ft_putstr_fd("Error : bad extention\n", 2), exit(1));
}

void	fetch_full_map(t_all *all)
{
	int		fd;
	int		height_full_map;
	int		i;
	char	*line;

	i = 0;
	all->ac = 2;
	check_file_extention(all);
	height_full_map = count_mapfile_height(all);
	fd = open(all->av[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error : error with mapfile\n", 2), exit(1));
	height_full_map++;
	all->full_map = ft_calloc((height_full_map + 1), sizeof(char *));
	(line = get_next_line(fd));
	while (line)
	{
		if (ft_strchr(line, '\n'))
			line[ft_strlen(line) - 1] = '\0';
		all->full_map[i] = ft_strdup(line);
		(free(line), i++);
		line = get_next_line(fd);
	}
	all->full_map[i] = NULL;
	ft_close(fd);
}
