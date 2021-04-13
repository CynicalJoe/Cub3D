#include "../include/cub3d.h"

t_game	*set_null(t_game *game)
{
	game->ray = NULL;
	game->text = NULL;
	game->data = NULL;
	game->map = NULL;
	game->path = NULL;
	game->cub = NULL;
	return (game);
}

t_game	*initialize_text(t_game *game)
{
	t_text *text;
	
	text = game->text;
	text->east = NULL;
	text->west = NULL;
	text->north = NULL;
	text->south = NULL;
	text->sprite = NULL;
	text->floor = 0;
	text->ceiling = 0;
	return (game);
}

t_game	*initialize_game(char **argv)
{
    t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit(EXIT_FAILURE);
	set_null(game);
	game->path = ft_strdup(argv[1]);
	if (!game->path)
		malloc_error(game);
	game->text = malloc(sizeof(t_text));
	if (!game->text)
		malloc_error(game);
	game->data = malloc(sizeof(t_data));
	if (!game->data)
		malloc_error(game);
	game->ray = malloc(sizeof(t_ray));
	if (!game->ray)
		malloc_error(game);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		malloc_error(game);
	initialize_text(game);
	return (game);
}