#include "../inc/so_long.h"

void	win_init(t_mlx_val *mlx)
{
	mlx->win_identifier = mlx_new_window(mlx->mlx_identifier,
			mlx->win_width, mlx->win_height, "so_long");
	mlx->win_image.img_identifier = mlx_new_image(mlx->mlx_identifier,
			mlx->win_width, mlx->win_height);
	mlx->win_image.addr_color_stored = mlx_get_data_addr(
			mlx->win_image.img_identifier, &mlx->win_image.bits_per_pixel,
			&mlx->win_image.line_length, &mlx->win_image.endian);
}

void	mlx_struct_init(t_mlx_val *mlx, char **map, char *filename)
{
	int	width;
	int	height;

	mlx->mlx_identifier = mlx_init();
	mlx->object_size = 64;
	mlx->map = map;
	mlx->player.move_count = 0;
	mlx->map_width = ft_strlen(*map);
	mlx->map_height = get_map_row_count(filename);
	width = mlx->object_size * mlx->map_width;
	height = mlx->object_size * mlx->map_height;
	mlx->win_width = width;
	mlx->win_height = height;
	mlx->collection_count = get_collection_count(mlx);
}
