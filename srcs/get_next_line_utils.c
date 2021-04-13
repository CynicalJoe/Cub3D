/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtournay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:16:12 by gtournay          #+#    #+#             */
/*   Updated: 2020/10/06 11:16:19 by gtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t n;

	n = 0;
	if (!s)
		return (0);
	while (s[n])
		n++;
	return (n);
}

int		next_line_check(char *rd_line)
{
	int i;

	i = 0;
	if (!rd_line)
		return (0);
	while (rd_line[i])
	{
		if (rd_line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dest, void *src, size_t len)
{
	unsigned char		*d;
	unsigned char		*s;
	long unsigned int	i;

	if (!src && !dest)
		return (NULL);
	d = dest;
	s = src;
	i = 0;
	if (d < s)
	{
		while (i < len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	else
	{
		while (len--)
			*(d + len) = *(s + len);
	}
	return (dest);
}

char	*joiner(char *rd_line, char *buffer)
{
	char	*result;
	size_t	len;

	if (!buffer && !rd_line)
		return (NULL);
	len = ft_strlen(rd_line) + ft_strlen(buffer);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memmove(result, rd_line, ft_strlen(rd_line));
	ft_memmove(result + ft_strlen(rd_line), buffer, ft_strlen(buffer));
	result[len] = '\0';
	free(rd_line);
	return (result);
}
