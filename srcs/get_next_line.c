/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:15:41 by gtournay          #+#    #+#             */
/*   Updated: 2020/09/22 11:49:05 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*rd_line_overwrite(char *rd_line)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!rd_line)
		return (NULL);
	while (rd_line[i] != '\n' && rd_line[i])
		i++;
	if (!rd_line[i])
	{
		free(rd_line);
		return (NULL);
	}
	i++;
	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(&rd_line[i]) + 1))))
		return (NULL);
	while (rd_line[i])
		result[j++] = rd_line[i++];
	result[j] = '\0';
	free(rd_line);
	return (result);
}

char	*line_overwrite(char *rd_line)
{
	int		i;
	char	*result;

	i = 0;
	if (!rd_line)
		return (0);
	while (rd_line[i] && rd_line[i] != '\n')
		i++;
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (rd_line[i] && rd_line[i] != '\n')
	{
		result[i] = rd_line[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*rd_line;
	int			ret_value;

	ret_value = 1;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!next_line_check(rd_line) && ret_value)
	{
		if ((ret_value = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[ret_value] = '\0';
		rd_line = joiner(rd_line, buffer);
	}
	free(buffer);
	*line = line_overwrite(rd_line);
	rd_line = rd_line_overwrite(rd_line);
	if (ret_value == 0)
		return (0);
	return (1);
}
