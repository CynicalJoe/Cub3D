/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:20:02 by gtournay          #+#    #+#             */
/*   Updated: 2021/03/24 13:20:09 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_game  *map_check_col(t_game *game)
{
	size_t	i;
	size_t	j;
	t_map	*map;

	i = 0;
	map = game->map;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] == ' ' && map->map[i][j])
			j++;
		if (map->map[i][j] != '1' )
			break;
		j = ft_strlen(map->map[i]);
		while (map->map[i][j] == ' ' && j > 0)
			j--;
		if (map->map[i][j] != '1')
			break;
		i++;
		if (map->map[i] == NULL)
			return (game);
	}
	return (NULL);
}

t_game	*map_check_row(t_game *game)
{
	size_t	i;
	size_t	j;
	t_map	*map;

	j = 0;
	map = game->map;
	while (j <= map->maxcol)
	{
		i = 0;
		while ((map->map[i][j] == ' ' || !map->map[i][j]) && i < map->row)
			i++;
		if (map->map[i][j] != '1')
			break;
		i = map->row;
		while ((map->map[i][j] == ' ' || !map->map[i][j]) && i > 0)
			i--;
		if (map->map[i][j] != '1')
			break;
		if (j == map->maxcol)
			return (game);
		j++;
	}
	return (NULL);
}

t_game	*check_map(t_game *game)
{
	size_t	i;
	size_t	j;
	t_map	*map;

	if (!map_check_row(game) || !map_check_col(game))
		invalid_map(game);
	i = 0;
	map = game->map;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!is_in_set(map->map[i][j], " 012NEWS"))
				invalid_map(game);
			j++;
		}
		i++;
	}
	return (game);	
}