#include "../inc/so_long.h"

t_mlx_val	open_window(char **map, char *filename)
{
	t_mlx_val	mlx;

	mlx_struct_init(&mlx, map, filename);
	win_init(&mlx);
	return (mlx);
}

void	render_game_object(t_mlx_val *mlx, char **map)
{
	select_xpm_file(mlx);
	draw_window(mlx, map);
	mlx_put_image_to_window(mlx->mlx_identifier, mlx->win_identifier,
		mlx->win_image.img_identifier, 0, 0);
}
