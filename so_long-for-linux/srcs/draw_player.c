#include "../inc/so_long.h"

static t_image_data	select_player_image(t_player player, int keycode)
{
	if (keycode == W)
		return (player.player_forward_img);
	else if (keycode == S)
		return (player.player_back_img);
	else if (keycode == A)
		return (player.player_left_img);
	else
		return (player.player_right_img);
}

void	draw_player(t_mlx_val *mlx, int map_col, int map_row, int keycode)
{
	int				i;
	int				j;
	unsigned int	color;
	t_image_data	player;

	i = 0;
	player = select_player_image(mlx->player, keycode);
	while (i < mlx->object_size)
	{
		j = 0;
		while (j < mlx->object_size)
		{
			color = get_color(&player, j, i);
			if (color != 0xff000000)
				draw_pixel(&mlx->win_image, j + map_col
					* mlx->object_size, i + map_row * mlx->object_size, color);
			j++;
		}
		i++;
	}
}
