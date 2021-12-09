#include "so_long.h"

int	ft_map_init(t_map *map, int fd)
{
	char *line;

	line = NULL;
	while (!line || *line != '1')
	{
		if (line)
			free(line);
		if (!get_next_line(fd, &line))
		{
			free(line);
			return (0);
		}
	}
	if (!ft_str_isset(line, "1"))
	{
		free(line);
		return (0);
	}
	map->width = ft_strlen(line);
	map->layout = line;
	return (1);
}

int	ft_add_row(t_map *map, char *line)
{
	if (!ft_check_row(line, map->width))
	{
		free(line);
		return (0);
	}
	map->layout = ft_str_fusion(map->layout, line);
	if (!map->layout)
		return (0);
	return (1);
}

int	ft_load_layout(t_map *map, int fd)
{
	char *line;

	line = NULL;
	map->height = 1;
	while (!line || !ft_str_isset(line, "1"))
	{
		if (line)
			free(line);
		if (!get_next_line(fd, &line))
		{
			if (!ft_str_isset(line, "1"))
			{
				free(line);
				return (0);
			}
		}
		if (!ft_add_row(map, line))
			return (0);
		map->height++;
	}
	free(line);
	return (1);
}

int	ft_load_map(t_map *map, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	map->layout = NULL;
	if (!ft_map_init(map, fd))
	{
		return (ft_exit_map(map, fd, MAP_OPEN));
	}
	if (!ft_load_layout(map, fd))
	{
		return (ft_exit_map(map, fd, MAP_NOT_REC));
	}
	close(fd);
	if (!ft_strchr_set(map->layout, CHARSET))
	{
		return (ft_exit_map(map, fd, MAP_CHARSET_NOT_FOUND));
	}
	if (ft_str_countc(map->layout, 'P') > 1)
	{
		return (ft_exit_map(map, fd, MAP_PLAYER_UBIQUITY));
	}
	return (1);
}

