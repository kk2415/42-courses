#include "../inc/so_long.h"

int	main(int arc, char *arg[])
{
	char		**map;
	t_mlx_val	mlx;

	if (arc != 2)
		return (0);
	map = get_map(arg[1]);
	check_map(map, arg[1]);
	mlx = open_window(map, arg[1]);
	render_game_object(&mlx, map);
	mlx_key_hook(mlx.win_identifier, key_hook, &mlx);
	mlx_hook(mlx.win_identifier, 17, 0, exit_hook, &mlx);
	mlx_loop(mlx.mlx_identifier);
}
