#include "../include/cub3d.h"


int close_window(int keycode, t_data *data)
{
	if (keycode == 53) 
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data);
		exit(0);
	}
	return 0;
}
