#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../Libft/libft.h"
# include <mlx.h>

# define ESCAPE 53
# define S 1
# define D 2
# define W 13
# define A 0

# define GROUND '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define WHITE 0xffffff
# define BLACK 0x0
# define RED 0xff0000
# define GREEN 0xff00
# define YELLOW 0xffff00
# define ORANGE 0xffa500
# define BLUE 0x2F32FF
# define DARK_BLUE 0x2F327A
# define LIGHT_GRAY 0xd3d3d3

typedef struct s_image_data
{
	void			*img_identifier;
	void			*addr_color_stored;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}	t_image_data;

typedef struct s_player
{
	int				x;
	int				y;
	int				move_count;
	t_image_data	player_back_img;
	t_image_data	player_forward_img;
	t_image_data	player_right_img;
	t_image_data	player_left_img;
}	t_player;

typedef struct s_wall
{
	t_image_data	wall_top;
	t_image_data	wall_bottom;
	t_image_data	wall_right;
	t_image_data	wall_left;
	t_image_data	wall_center;
	t_image_data	wall_dl_corner;
	t_image_data	wall_dr_corner;
	t_image_data	wall_ul_corner;
	t_image_data	wall_ur_corner;
}	t_wall;

typedef struct s_mlx_val
{
	void			*mlx_identifier;
	void			*win_identifier;
	int				collection_count;
	int				win_width;
	int				win_height;
	int				object_size;
	int				map_width;
	int				map_height;
	char			**map;
	t_image_data	win_image;
	t_image_data	collection_img;
	t_image_data	exit_img;
	t_image_data	ground_img;
	t_wall			wall;
	t_player		player;
}	t_mlx_val;

void			draw_ground(t_mlx_val *mlx, t_image_data *img,
					int map_col, int map_row);
void			draw_player(t_mlx_val *mlx, int map_col, int map_row,
					int keycode);
void			draw_wall(t_mlx_val *mlx, int map_col, int map_row);
int				draw_window(t_mlx_val *mlx, char **map);
void			draw_pixel(t_image_data *img, int x, int y, int color);
unsigned int	get_color(t_image_data *img, int x, int y);

void			check_map(char **map, char *filename);
char			**get_map(char *filename);
int				get_map_row_count(char *filename);
void			map_free_fun(char **map);
int				get_collection_count(t_mlx_val *mlx);

int				exit_hook(t_mlx_val *mlx);
int				key_hook(int keycode, t_mlx_val *mlx);
t_mlx_val		open_window(char **map, char *filename);
void			render_game_object(t_mlx_val *mlx, char **map);
void			win_init(t_mlx_val *mlx);
void			mlx_struct_init(t_mlx_val *mlx, char **map, char *filename);
void			destroy_player_image(void *mlx_identifier, t_player player);
void			destroy_wall_image(void *mlx_identifier, t_wall wall);
void			destroy_gorund_image(void *mlx_identifier,
					t_image_data ground_img);
void			destroy_exit_image(void *mlx_identifier, t_image_data exit_img);
void			select_xpm_file(t_mlx_val *mlx);

void			move_player(t_mlx_val *mlx, int keycode);

#endif
