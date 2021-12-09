#include "so_long.h"

int	ft_check_row(char *line, int width)
{
	int i;

	i = 0;
	if (*line != '1')
	{
		return (0);
	}
	while (line[i + 1])
	{
		if (!ft_str_isset(line, CHARSET))
		{
			return (0);
		}
		i++;
	}
	if (line[i] != '1' || i + 1 != width)
		return (0);
	return (1);
}

int	ft_exit_map(t_map *map, int fd, int errnb)
{
	if (map->layout)
		free(map->layout);
	close(fd);
	ft_manage_error(errnb);
	return (0);
}
