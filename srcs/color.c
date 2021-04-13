#include "../include/cub3d.h"

int str_to_color(char *str)
{
	size_t  i;
	int     color;
	
	i = 0;
	color = 0;
	while (str[i] < '0' && str[i] > '9' && str[i])
		i++;
	color = (color << 8) + ft_atoi(&str[i]);
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		i++;
	while (str[i] < '0' && str[i] > '9' && str[i])
		i++;
	color = (color << 8) + ft_atoi(&str[i]);
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		i++;
	while (str[i] < '0' && str[i] > '9' && str[i])
		i++;
	color = (color << 8) + ft_atoi(&str[i]);
	//if (!str[i]) return error statement about color
	return (color);
}