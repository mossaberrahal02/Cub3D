#include "cub3d.h"

void	ft_close(int fd)
{
	if (close(fd) == -1)
	{
		// TODO free what should be freed
		return (ft_putstr_fd("error closing file\n", 2), exit(2));
	}
}

int	count_mapfile_height(void)
{
	char	*line;

	int(fd), (i);
	fd = open("./maps/map.cub", O_RDONLY);
	i = 0;
	if (fd < 0)
		return (ft_putstr_fd("error with mapfile\n", 2), exit(2), 1);
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

void	fetch_map(t_all *all)
{
	int		fd;
	int		height_full_map;
	int		i;
	char	*line;

	i = 0;
	all->ac = 2;
	// int width_full_map;
	height_full_map = count_mapfile_height();
	fd = open("./maps/map.cub", O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("fd < 0\n", 2), exit(2));
	height_full_map++;
	all->full_map = ft_calloc((height_full_map + 1), sizeof(char *));
	(line = get_next_line(fd));
	while (line)
	{
		if (ft_strchr(line, '\n'))
			line[ft_strlen(line) - 1] = '\0';
		all->full_map[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	all->full_map[i] = NULL;
	ft_close(fd);
}

void	parsing(t_all *all, int ac, char **av)
{
	int	i;

	all->ac = ac;
	all->av = av;
	fetch_map(all);
	i = 0;
	while (all->full_map[i])
	{
		printf("%s", all->full_map[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_all *all;
    all = ft_calloc(1, sizeof(t_all));
	if (ac != 2)
		return (ft_putstr_fd("bad arguments\n", 2), 1);
	parsing(all, ac, av);
}
