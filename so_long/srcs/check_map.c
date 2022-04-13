#include "../inc/so_long.h"

static void	error(char *string, char **map)
{
	printf("Error\n%s\n", string);
	map_free_fun(map);
	exit(1);
}

static int	is_map_surrounded_by_wall(char	**map, char *filename)
{
	int	map_width;
	int	map_height;
	int	map_row;
	int	map_col;

	map_row = 0;
	map_width = ft_strlen(*map);
	map_height = get_map_row_count(filename);
	while (map[map_row])
	{
		map_col = -1;
		while (map[map_row][++map_col])
		{
			if (map_row == 0 && map[map_row][map_col] != '1')
				return (0);
			else if (map_col == 0 && map[map_row][map_col] != '1')
				return (0);
			else if (map_col == map_width - 1 && map[map_row][map_col] != '1')
				return (0);
			else if (map_row == map_height - 1 && map[map_row][map_col] != '1')
				return (0);
		}
		map_row++;
	}
	return (1);
}

static int	find(char **map, char ch)
{
	int	map_row;

	map_row = 0;
	while (map[map_row])
	{
		if (ft_strchr(map[map_row], ch))
			return (1);
		map_row++;
	}
	return (0);
}

static void	check_each_row_of_map(char **map)
{
	int	map_row;
	int	row_len;

	map_row = 0;
	row_len = ft_strlen(*map);
	while (map[map_row])
	{
		if (row_len != (int)ft_strlen(map[map_row]))
			error("The length of the map is weird", map);
		map_row++;
	}
}

void	check_map(char **map, char *filename)
{
	check_each_row_of_map(map);
	if (!is_map_surrounded_by_wall(map, filename))
		error("map is not surrounded by wall", map);
	if ((int)ft_strlen(*map) == get_map_row_count(filename))
		error("Map is not rectangular", map);
	else if (!find(map, 'P'))
		error("Could not find Starting Point on the map", map);
	else if (!find(map, 'E'))
		error("Could not find Exit on the map", map);
	else if (!find(map, 'C'))
		error("Could not find Collection on the map", map);
}
