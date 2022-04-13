#include "../inc/so_long.h"

void	map_free_fun(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	get_collection_count(t_mlx_val *mlx)
{
	int	collection_count;
	int	row;
	int	col;

	row = 0;
	collection_count = 0;
	while (mlx->map[row])
	{
		col = 0;
		while (mlx->map[row][col])
		{
			if (mlx->map[row][col] == COLLECTIBLE)
				collection_count++;
			col++;
		}
		row++;
	}
	return (collection_count);
}

int	get_map_row_count(char *filename)
{
	char	*map_line;
	int		count;
	int		fd;

	count = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &map_line))
	{
		count++;
		free(map_line);
	}
	free(map_line);
	close(fd);
	return (count);
}

char	**get_map(char *filename)
{
	int		i;
	int		fd;
	char	**map;
	char	*map_line;
	int		map_row_count;

	if (!ft_strnstr(filename, ".ber", ft_strlen(filename)))
	{
		printf("Error\nfilename is weird\n");
		exit(1);
	}
	i = 0;
	fd = open(filename, O_RDONLY);
	map_row_count = get_map_row_count(filename);
	map = (char **)malloc(sizeof(char *) * (map_row_count + 1));
	while (get_next_line(fd, &map_line))
	{
		map[i] = map_line;
		i++;
	}
	map[i] = NULL;
	free(map_line);
	close(fd);
	return (map);
}
