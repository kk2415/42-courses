#include "../inc/so_long.h"

void	destroy_player_image(void *mlx_identifier, t_player player)
{
	mlx_destroy_image(mlx_identifier, player.player_back_img.img_identifier);
	mlx_destroy_image(mlx_identifier, player.player_forward_img.img_identifier);
	mlx_destroy_image(mlx_identifier, player.player_left_img.img_identifier);
	mlx_destroy_image(mlx_identifier, player.player_right_img.img_identifier);
}

void	destroy_wall_image(void *mlx_identifier, t_wall wall)
{
	mlx_destroy_image(mlx_identifier, wall.wall_bottom.img_identifier);
	mlx_destroy_image(mlx_identifier, wall.wall_center.img_identifier);
	mlx_destroy_image(mlx_identifier, wall.wall_left.img_identifier);
	mlx_destroy_image(mlx_identifier, wall.wall_right.img_identifier);
	mlx_destroy_image(mlx_identifier, wall.wall_top.img_identifier);
	mlx_destroy_image(mlx_identifier, wall.wall_dl_corner.img_identifier);
	mlx_destroy_image(mlx_identifier, wall.wall_dr_corner.img_identifier);
	mlx_destroy_image(mlx_identifier, wall.wall_ur_corner.img_identifier);
	mlx_destroy_image(mlx_identifier, wall.wall_ul_corner.img_identifier);
}

void	destroy_gorund_image(void *mlx_identifier, t_image_data ground_img)
{
	mlx_destroy_image(mlx_identifier, ground_img.img_identifier);
}

void	destroy_exit_image(void *mlx_identifier, t_image_data exit_img)
{
	mlx_destroy_image(mlx_identifier, exit_img.img_identifier);
}
