#include "../include/cub3d.h"

void            my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char    *dst;

	dst = game->data->addr + (y * game->data->line_length + x * (game->data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_game *game, int x, int color)
{
	int lineh;

	lineh = (int)(game->data->screen_hgt / (game->ray->perpwalldist));
	game->ray->drawstart = ((-lineh / 2) + game->data->screen_hgt / 2);
	if (game->ray->drawstart < 0)
		game->ray->drawstart = 0;
	game->ray->drawend = ((lineh / 2) + game->data->screen_hgt / 2);
	if (game->ray->drawend >= game->data->screen_hgt)
		game->ray->drawend = game->data->screen_hgt - 1;
	while (game->ray->drawstart < game->ray->drawend)
	{
		my_mlx_pixel_put(game, x, game->ray->drawstart, color);
		game->ray->drawstart++;

	}
}

int		gen_new_image(t_game *game)
{
	t_data *data;

	data = game->data;
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->screen_wth, data->screen_hgt);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	raycasting(game);
	mlx_put_image_to_window(data->mlx, data->win, data->img, -1, 0);
	return (0);
}
