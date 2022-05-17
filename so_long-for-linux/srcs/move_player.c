#include "../inc/so_long.h"

static short	**movement_arr_init(void)
{
	int		i;
	short	**movement;

	i = 0;
	movement = (short **)malloc(sizeof(short *) * 121);
	while (i < 120)
	{
		movement[i] = (short *)malloc(sizeof(short ) * 3);
		i++;
	}
	movement[W][0] = 0;
	movement[W][1] = -1;
	movement[A][0] = -1;
	movement[A][1] = 0;
	movement[S][0] = 0;
	movement[S][1] = 1;
	movement[D][0] = 1;
	movement[D][1] = 0;
	return (movement);
}

static void	movement_arr_free(short **movement)
{
	int	i;

	i = 0;
	while (i < 120)
	{
		free(movement[i]);
		i++;
	}
	free(movement);
}

void	move_player(t_mlx_val *mlx, int keycode)
{
	int		new_x;
	int		new_y;
	short	**movement;

	movement = movement_arr_init();
	new_x = mlx->player.x + movement[keycode][0];
	new_y = mlx->player.y + movement[keycode][1];
	if (mlx->map[new_y][new_x] == WALL)
		return ;
	if (mlx->map[new_y][new_x] == COLLECTIBLE)
		mlx->collection_count--;
	if (mlx->map[new_y][new_x] == EXIT)
	{
		if (mlx->collection_count > 0)
			return ;
		movement_arr_free(movement);
		exit_hook(mlx);
	}
	draw_ground(mlx, &mlx->ground_img, mlx->player.x, mlx->player.y);
	draw_player(mlx, new_x, new_y, keycode);
	mlx->player.move_count++;
	printf("Current Number Of Movements: %03d\n", mlx->player.move_count);
	mlx->player.x = new_x;
	mlx->player.y = new_y;
	movement_arr_free(movement);
}
