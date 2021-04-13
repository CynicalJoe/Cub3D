/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:21:46 by gtournay          #+#    #+#             */
/*   Updated: 2021/03/24 15:21:52 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_game	*free_text(t_game *game)
{
	if (game->text->north)
		free(game->text->north);
	if (game->text->south)
		free(game->text->south);
	if (game->text->east)
		free(game->text->east);
	if (game->text->west)
		free(game->text->west);
	if (game->text->sprite)
		free(game->text->sprite);
	/**if (game->text->floor)
		free(game->text->floor);
	if (game->text->ceiling)
		free(game->text->ceiling);
	**/return (game);
}

t_game	*free_map(t_game *game)
{
	if (game->map->map)
		free(game->map->map);
	return (game);
}

void	free_game(t_game *game)
{
	size_t i;
	i = 0;
	if (game->cub)
	{
		while (game->cub[i])
		{
			free(game->cub[i]);
			i++;
		}
		free(game->cub);
	}
	if (game->path)
		free(game->path);
	if (game->ray)
		free(game->ray);
	if (game->data)
		free(game->data);
	if (game->text)
		free(game->text);
	if (game->map)
		free(game->map);
	free(game);
}