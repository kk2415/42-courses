#include "../inc/so_long.h"

void	draw_ground(t_mlx_val *mlx, t_image_data *img, int map_col, int map_row)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < mlx->object_size)
	{
		j = 0;
		while (j < mlx->object_size)
		{
			color = get_color(img, j, i);
			if (color != 0xff000000)
				draw_pixel(&mlx->win_image, j + map_col
					* mlx->object_size, i + map_row * mlx->object_size, color);
			j++;
		}
		i++;
	}
}
