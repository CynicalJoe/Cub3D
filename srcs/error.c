/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:09:22 by gtournay          #+#    #+#             */
/*   Updated: 2021/03/24 15:09:27 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	invalid_map(t_game *game)
{
	free_text(game);
	free_map(game);
	free_game(game);
	printf("Error\nInvalid map detected\n");
	exit(EXIT_FAILURE);
}

void	invalid_cub(t_game *game)
{
	free_game(game);
	printf("Error\nMisconfigured .cub file\n");
	exit(EXIT_FAILURE);
}

void malloc_error(t_game *game)
{
	free_text(game);
	free_map(game);
	free_game(game);
	printf("Error\nProgram failed to allocate memory\n");
	exit(EXIT_FAILURE);
}

void check_cub(int argc, char **argv)
{
	size_t i;

	i = 0;
	if (argc == 1)
	{
		printf("Error\nMissing .cub file\n");
		exit(EXIT_FAILURE);
	}
	if (argc > 3)
	{
		printf("%s%s","Error\nToo many arguments\nUsage : cub3D [.cub] [option]",
		"\n\t option : --save\tsave first image to bmp format\n");
		exit(EXIT_FAILURE);
	}
	while (argv[1][i] == '.' && argv[1][i])
		i++;
	while (argv[1][i] && argv[1][i] != '.')
		i++;
	if (!argv[1][i] || ft_strncmp(&argv[1][i], ".cub", 4) != 0)
	{
		printf("Error\nUnrecognized configuration file\n");
		exit(EXIT_FAILURE);
	}
}