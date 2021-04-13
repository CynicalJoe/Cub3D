#include "../include/cub3d.h"
#include <stdio.h>
#include <unistd.h>

/*t_data *draw_cube(t_data *data, int len, int startx, int starty, int color)
{
	int x = startx;
	int y = starty;

	while (x < len +startx)
	{
		y = starty;
		while (y < len +starty)
		{
			my_mlx_pixel_put(data, x , y, color);
			y++;
		}
		x++;
	}
	return (data);
}*/

int main(int argc, char **argv)
{
	t_game *game;

	check_cub(argc, argv);
	game = initialize_game(argv);
	game->data->img = NULL;
	get_cub(game);
	get_map(game);
	init_raycast(game);
	printf("%d\n", game->text->ceiling);
	printf("%d\n", game->text->floor);
	game->data->mlx = mlx_init();
	game->data->win = mlx_new_window(game->data->mlx, game->data->screen_wth, game->data->screen_hgt, "test");
	mlx_loop_hook(game->data->mlx, gen_new_image, game);
	mlx_key_hook(game->data->win, move_pov, game);
	mlx_loop(game->data->mlx);
	return 0;
}