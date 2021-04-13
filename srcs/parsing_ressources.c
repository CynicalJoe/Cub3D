#include "../include/cub3d.h"

int		ft_isspace(char c)
{
	if (c == 32 || (9 <= c && c <= 13))
		return (1);
	else
		return (0);
}

int		is_in_set(char c, char *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

t_game	*get_texture(t_game *game, size_t i, size_t j, int mode)
{
	j++;
	if (mode <= 4)
		j++;
	while(ft_isspace(game->cub[i][j]) && game->cub[i][j])
		j++;
	if (mode == 1)
		game->text->north = ft_strdup(&game->cub[i][j]);
	else if (mode == 2)
		game->text->west = ft_strdup(&game->cub[i][j]);
	else if (mode == 3)
		game->text->east = ft_strdup(&game->cub[i][j]);
	else if (mode == 4)
		game->text->south = ft_strdup(&game->cub[i][j]);
	else if (mode == 5)
		game->text->sprite = ft_strdup(&game->cub[i][j]);
	else if (mode == 6)
		game->text->floor = str_to_color(&game->cub[i][j]); //modifiy to add color creation function
	else if (mode == 7)
		game->text->ceiling = str_to_color(&game->cub[i][j]); // same here
	return (game);
}

t_game	*get_resolution(t_game *game, size_t i, size_t j)
{
	j++;
	while(ft_isspace(game->cub[i][j]) && game->cub[i][j])
		j++;
	game->data->screen_wth = ft_atoi(&game->cub[i][j]);
	while (ft_isdigit(game->cub[i][j]) && game->cub[i][j])
		j++;
	game->data->screen_hgt = ft_atoi(&game->cub[i][j]);
	if (!game->data->screen_hgt || !game->data->screen_wth)
		invalid_cub(game); 
	return (game);
}

t_game	*handle_start(t_game *game, size_t i, size_t j)
{
	if (game->map->map[i][j] == 'N')
	{
		game->ray->dirx = -1;
		game->ray->diry = 0;
	}
	else if (game->map->map[i][j] == 'S')
	{
		game->ray->dirx = 1;
		game->ray->diry = 0;
	}
	else if (game->map->map[i][j] == 'E')
	{
		game->ray->dirx = 0;
		game->ray->diry = -1;
	}
	else if (game->map->map[i][j] == 'W')
	{
		game->ray->dirx = 0;
		game->ray->diry = 1;
	}
	return (game);
}