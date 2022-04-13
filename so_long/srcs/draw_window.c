#include "../inc/so_long.h"

static void	select_image(t_mlx_val *mlx, char image, int map_col, int map_row)
{
	if (image == GROUND)
		draw_ground(mlx, &mlx->ground_img, map_col, map_row);
	else if (image == WALL)
	{
		draw_ground(mlx, &mlx->ground_img, map_col, map_row);
		draw_wall(mlx, map_col, map_row);
	}
	else if (image == COLLECTIBLE)
	{
		draw_ground(mlx, &mlx->ground_img, map_col, map_row);
		draw_ground(mlx, &mlx->collection_img, map_col, map_row);
	}
	else if (image == EXIT)
	{
		draw_ground(mlx, &mlx->ground_img, map_col, map_row);
		draw_ground(mlx, &mlx->exit_img, map_col, map_row);
	}
	else if (image == PLAYER)
	{
		mlx->player.x = map_col;
		mlx->player.y = map_row;
		draw_ground(mlx, &mlx->ground_img, map_col, map_row);
		draw_player(mlx, map_col, map_row, S);
	}
}

int	draw_window(t_mlx_val *mlx, char **map)
{
	int	map_col;
	int	map_row;

	map_row = 0;
	map_col = 0;
	while (map[map_row])
	{
		map_col = 0;
		while (map[map_row][map_col])
		{
			select_image(mlx, map[map_row][map_col], map_col, map_row);
			map_col++;
		}
		map_row++;
	}
	return (0);
}
