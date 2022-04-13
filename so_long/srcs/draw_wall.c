#include "../inc/so_long.h"

static t_image_data	select_corner_wall_image(t_mlx_val *mlx, t_wall wall
, int map_col, int map_row)
{
	if (map_row == 0 && map_col == 0)
		return (wall.wall_ul_corner);
	else if (map_row == 0 && map_col == mlx->map_width - 1)
		return (wall.wall_ur_corner);
	else if (map_row == mlx->map_height - 1 && map_col == 0)
		return (wall.wall_dl_corner);
	else
		return (wall.wall_dr_corner);
}

static t_image_data	select_wall_image(t_mlx_val *mlx, t_wall wall, int map_col
, int map_row)
{
	if (map_col == 0 && map_row != 0 && map_row != mlx->map_height - 1)
		return (wall.wall_left);
	else if (map_col == mlx->map_width - 1 && map_row != 0 && map_row
		!= mlx->map_height - 1)
		return (wall.wall_right);
	else if (map_row == 0 && map_col != 0 && map_col != mlx->map_width - 1)
		return (wall.wall_top);
	else if (map_row == mlx->map_height - 1 && map_col != 0 && map_col
		 != mlx->map_width - 1)
		return (wall.wall_bottom);
	else if (map_row != 0 && map_row != mlx->map_height - 1)
		return (wall.wall_center);
	else
		return (select_corner_wall_image(mlx, wall, map_col, map_row));
}

void	draw_wall(t_mlx_val *mlx, int map_col, int map_row)
{
	int				i;
	int				j;
	t_image_data	wall;
	unsigned int	color;

	i = 0;
	wall = select_wall_image(mlx, mlx->wall, map_col, map_row);
	while (i < mlx->object_size)
	{
		j = 0;
		while (j < mlx->object_size)
		{
			color = get_color(&wall, j, i);
			if (color != 0xff000000)
				draw_pixel(&mlx->win_image, j + map_col
					* mlx->object_size, i + map_row * mlx->object_size, color);
			j++;
		}
		i++;
	}
}
