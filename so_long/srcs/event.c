#include "../inc/so_long.h"

int	exit_hook(t_mlx_val *mlx)
{
	mlx_destroy_image(mlx->mlx_identifier, mlx->win_image.img_identifier);
	destroy_player_image(mlx->mlx_identifier, mlx->player);
	destroy_wall_image(mlx->mlx_identifier, mlx->wall);
	destroy_gorund_image(mlx->mlx_identifier, mlx->ground_img);
	destroy_exit_image(mlx->mlx_identifier, mlx->exit_img);
	mlx_destroy_window(mlx->mlx_identifier, mlx->win_identifier);
	map_free_fun(mlx->map);
	exit(0);
}

int	key_hook(int keycode, t_mlx_val *mlx)
{
	if (keycode == ESCAPE)
	{
		exit_hook(mlx);
	}
	else if (keycode == W || keycode == S || keycode == A || keycode == D)
	{
		move_player(mlx, keycode);
		mlx_put_image_to_window(mlx->mlx_identifier, mlx->win_identifier,
			mlx->win_image.img_identifier, 0, 0);
	}
	return (0);
}
