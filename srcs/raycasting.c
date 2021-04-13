#include "../include/cub3d.h"

t_game *init_raycast(t_game *game)
{
	get_start_param(game);
	if (game->ray->diry)
	{
		game->ray->planex = 0.66;
		game->ray->planey = 0.00;
	}
	else
	{
		game->ray->planex = 0.00;
		game->ray->planey = 0.66;
	}
	return (game);
}

t_game *raycasting(t_game *game)
{
	int     x;
	t_ray   *ray;
	
	x = 0;
	ray = game->ray;
	
	while (x  < game->data->screen_wth)
	{
		ray->camerax =  (2 * x) / (double)game->data->screen_wth - 1;
		ray->raydirx = ray->dirx + ray->planex * ray->camerax;
		ray->raydiry = ray->diry + ray->planey * ray->camerax;
		ray->mapx = (int)ray->posx;
		ray->mapy = (int)ray->posy;
		ray->deltadistx = fabs(1/ray->raydirx);
		ray->deltadisty = fabs(1/ray->raydiry);
		ray->hit = 0;
		if (ray->raydirx < 0)
		{
			ray->stepx = -1;
			ray->sidedistx = (ray->posx - ray->mapx) * ray->deltadistx;
		}
		else
		{
			ray->stepx = 1;
			ray->sidedistx = (ray->mapx + 1 - ray->posx) * ray->deltadistx;
		}
		if (ray->raydiry < 0)
		{
			ray->stepy = -1;
			ray->sidedisty = (ray->posy - ray->mapy) * ray->deltadisty;
		}
		else
		{
			ray->stepy = 1;
			ray->sidedisty = (ray->mapy + 1 - ray->posy) * ray->deltadisty;
		}
		while (!ray->hit)
		{
			if (ray->sidedisty > ray->sidedistx)
			{
				ray->sidedistx += ray->deltadistx;
				ray->mapx += ray->stepx;
				ray->side = 0; 
			}
			else
			{
				ray->sidedisty += ray->deltadisty;
				ray->mapy += ray->stepy;
				ray->side = 1;
			}
			if (game->map->map[ray->mapx][ray->mapy] == '1')
				ray->hit = 1;
		}
		printf("%d\n", ray->mapx);
		printf("%d\n", ray->mapy);
		if (ray->side == 0)
			ray->perpwalldist = (ray->mapx - ray->posx + (1 - ray->stepx) / 2 ) / ray->raydirx;
		else
			ray->perpwalldist = (ray->mapy - ray->posy + (1 - ray->stepy) / 2) / ray->raydiry;
		if (ray->side == 1)
			draw_line(game, x,  0x00FF0000);
		else
			draw_line(game, x , 0x00FF00FF);
		x++;
	}
	return (game);
}