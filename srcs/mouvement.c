#include "../include/cub3d.h"

int	move_vert(int keycode, t_game *game)
{
	t_ray *ray;
	
	ray = game->ray;
	if (keycode == 122)
	{
		if (game->map->map[(int)ray->posx + (int)ray->dirx][(int)game->ray->posy] != '1')
			game->ray->posx += ray->dirx;
		if (game->map->map[(int)(ray->posx)][(int)ray->posy + (int)(ray->diry)] != '1')
			ray->posy += ray->diry;
	}
	if (keycode == 115)
	{
		if (game->map->map[(int)(ray->posx - ray->dirx)][(int)(game->ray->posy)] != '1')
			game->ray->posx -= ray->dirx;
		if (game->map->map[(int)(ray->posx)][(int)(ray->posy - ray->diry)] != '1')
			ray->posy -= ray->diry;
	}
	return (0);
}

int	straff(int keycode, t_game *game)
{
	t_ray *ray;
	
	ray = game->ray;
	if (keycode == 113)
	{
		if (game->map->map[(int)ray->posx + (int)ray->diry][(int)game->ray->posy] != '1')
			game->ray->posx += ray->diry;
		if (game->map->map[(int)(ray->posx)][(int)ray->posy + (int)(ray->dirx)] != '1')
			ray->posy += ray->dirx;
	}
	if (keycode == 100)
	{	
		if (game->map->map[(int)ray->posx - (int)ray->diry][(int)game->ray->posy] != '1')
			game->ray->posx -= ray->diry;
		if (game->map->map[(int)(ray->posx)][(int)ray->posy - (int)(ray->dirx)] != '1')
			ray->posy -= ray->dirx;
	}
	return (0);
}

int	move_pov(int keycode, t_game *game)
{
	if (keycode == 122 || keycode == 115)
		move_vert(keycode, game);
	else if (keycode == 113 || keycode == 100)
		straff(keycode, game);
	return (0);
}
