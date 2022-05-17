#include "../inc/so_long.h"

void	draw_pixel(t_image_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr_color_stored + (y * img->line_length + x
			* (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color(t_image_data *img, int x, int y)
{
	return (*(unsigned int *)
		(img->addr_color_stored + (x * img->bits_per_pixel / 8
				+ y * img->line_length)));
}
