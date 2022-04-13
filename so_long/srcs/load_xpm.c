#include "../inc/so_long.h"

static void	xpm_file_to_memory(t_mlx_val *mlx, t_image_data *img,
char *filename)
{
	img->img_identifier = mlx_xpm_file_to_image(mlx->mlx_identifier,
			filename, &img->width, &img->height);
	img->addr_color_stored = mlx_get_data_addr(img->img_identifier,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}

void	select_xpm_file(t_mlx_val *mlx)
{
	xpm_file_to_memory(mlx, &mlx->player.player_back_img,
		"./image/player_back.xpm");
	xpm_file_to_memory(mlx, &mlx->player.player_forward_img,
		"./image/player_forward.xpm");
	xpm_file_to_memory(mlx, &mlx->player.player_right_img,
		"./image/player_right.xpm");
	xpm_file_to_memory(mlx, &mlx->player.player_left_img,
		"./image/player_left.xpm");
	xpm_file_to_memory(mlx, &mlx->wall.wall_center, "./image/wall_center.xpm");
	xpm_file_to_memory(mlx, &mlx->wall.wall_top, "./image/wall_top.xpm");
	xpm_file_to_memory(mlx, &mlx->wall.wall_bottom, "./image/wall_bottom.xpm");
	xpm_file_to_memory(mlx, &mlx->wall.wall_left, "./image/wall_left.xpm");
	xpm_file_to_memory(mlx, &mlx->wall.wall_right, "./image/wall_right.xpm");
	xpm_file_to_memory(mlx, &mlx->wall.wall_dl_corner,
		"./image/wall_dl_corner.xpm");
	xpm_file_to_memory(mlx, &mlx->wall.wall_dr_corner,
		"./image/wall_dr_corner.xpm");
	xpm_file_to_memory(mlx, &mlx->wall.wall_ul_corner,
		"./image/wall_ul_corner.xpm");
	xpm_file_to_memory(mlx, &mlx->wall.wall_ur_corner,
		"./image/wall_ur_corner.xpm");
	xpm_file_to_memory(mlx, &mlx->ground_img, "./image/ground.xpm");
	xpm_file_to_memory(mlx, &mlx->collection_img, "./image/collection.xpm");
	xpm_file_to_memory(mlx, &mlx->exit_img, "./image/exit.xpm");
}
