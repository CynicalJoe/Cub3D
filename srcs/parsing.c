/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:35:05 by gtournay          #+#    #+#             */
/*   Updated: 2021/03/11 11:35:16 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_game	*get_cub(t_game *game)
{
	int		fd;
	size_t	i;
	char	*line;

	i = 0;
	fd = open(game->path,O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		i++;
	}
	free(line);
	close(fd);
	fd = open(game->path,O_RDONLY);
	game->cub = malloc(sizeof(char *) * (i + 2));
	if (!game->cub)
		malloc_error(game);
	i = 0;
	while (get_next_line(fd, &line) > 0)
		game->cub[i++] = line;
	game->cub[i++] = line;
	game->cub[i] = NULL;
	return (game);
}

t_game	*copy_map(t_game *game, size_t i, size_t j)
{
	j = i;
	while(game->cub[i])
		i++;
	game->map->map = malloc(sizeof(char *) * (i - j + 1));
	if (!game->map->map)
		malloc_error(game);
	i = j;
	j = 0;
	game->map->maxcol = 0;
	while(game->cub[i])
	{
		if (ft_strlen(game->cub[i]) > game->map->maxcol)
			game->map->maxcol = ft_strlen(game->cub[i]);
		game->map->map[j++] = game->cub[i++];
	}
	game->map->map[j] = NULL;
	game->map->row = j - 1;
	return(game);
}

t_game   *get_map(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (game->cub[i])
	{
		j = 0;
		while (ft_isspace(game->cub[i][j]) && game->cub[i][j])
			j++;
		if (game->cub[i][j] != '1')
		{
			get_data(game, i, j);
			i++;
		}
		else
			break;
	}
	if (!game->cub[i])
		invalid_map(game);
	copy_map(game, i , j);
	return (game);
}

t_game *get_data(t_game *game, size_t i, size_t j)
{
	if (!ft_strncmp(&game->cub[i][j], "NO", 2))
		get_texture(game, i, j, 1);
	else if (!ft_strncmp(&game->cub[i][j], "WE", 2))
		get_texture(game, i, j, 2);
	else if (!ft_strncmp(&game->cub[i][j], "EA", 2))
		get_texture(game, i, j, 3);
	else if (!ft_strncmp(&game->cub[i][j], "SO", 2))
		get_texture(game, i, j, 4);
	else if (!ft_strncmp(&game->cub[i][j], "S", 1))
		get_texture(game, i, j, 5);
	else if (!ft_strncmp(&game->cub[i][j], "R", 1))
		get_resolution(game, i, j);
	else if (!ft_strncmp(&game->cub[i][j], "F", 1))
		get_texture(game, i, j, 6);
	else if (!ft_strncmp(&game->cub[i][j], "C", 1))
		get_texture(game, i, j, 7);
	else if (game->cub[i][j])
		invalid_cub(game);
	return (game);
}

t_game	*get_start_param(t_game *game)
{
	size_t i;
	size_t j;

	i = 0;
	while (game->map->map[i])
	{
		j = 0;
		while (game->map->map[i][j] && is_in_set(game->map->map[i][j], " 012"))
			j++;
		if (!game->map->map[i][j] || game->map->map[i][j] == '\n')
			i++;
		else if (is_in_set(game->map->map[i][j], "NSWE"))
		{
			game->ray->posx = i;
			game->ray->posy = j;
			handle_start(game, i, j);
			return (game);
		}
		else
			return (game); // invalid map
	}
	return (game); //no starting position found
}