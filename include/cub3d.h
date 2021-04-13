#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx_linux/mlx.h"
# include "get_next_line.h"
# include "../srcs/libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

/* up arrow is : 126
down : 125
left : 123
right : 124
w : 13
a : 0
s : 1
d : 2
*/
typedef struct	s_text{
	
	char		*north;
	char		*east;
	char		*west;
	char		*south;
	char		*sprite;
	int			floor;
	int			ceiling;
}				t_text;

typedef struct	s_ray {
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			x;
	float		stepx;
	float		stepy;
	int			hit;
	int			side;
	int			mapx;
	int			mapy;
	int			drawstart;
	int			drawend;
}				t_ray;

typedef struct	s_data {
	void        *img;
	void		*mlx;
	void		*win;
	char        *addr;
	int			screen_wth;
	int			screen_hgt;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}				t_data;

typedef struct	s_map
{
	char		**map;
	size_t		row;
	size_t		maxcol;

}				t_map;

typedef	struct	s_game 
{
	char		*path;
	t_ray 		*ray;
	t_data		*data;
	t_map		*map;
	t_text		*text;
	char		**cub;

}				t_game;

int				ft_isspace(char c);

int				is_in_set(char c, char *set);

int				close_window(int keycode, t_data *data);

int				gen_new_image(t_game *game);

int				str_to_color(char *str);

int				move_pov(int keycode, t_game *game);

void            my_mlx_pixel_put(t_game* game, int x, int y, int color);

void			draw_line(t_game *game, int x, int color);

void			free_game(t_game *game);

void			invalid_map(t_game *game);

void			invalid_cub(t_game *game);

void			malloc_error(t_game *game);

void			check_cub(int argc, char **argv);

t_game			*initialize_game(char **argv);

t_game			*get_cub(t_game *game);

t_game   		*get_map(t_game *game);

t_game			*copy_map(t_game *game, size_t i, size_t j);

t_game			*check_map(t_game *game);

t_game			*get_data(t_game *game, size_t i, size_t j);

t_game			*get_texture(t_game *game, size_t i, size_t j, int mode);

t_game			*get_resolution(t_game *game, size_t i, size_t j);

t_game			*get_start_param(t_game *game);

t_game 			*init_raycast(t_game *game);

t_game			*handle_start(t_game *game, size_t i, size_t j);

t_game 			*raycasting(t_game *game);

t_game			*free_text(t_game *game);

t_game			*free_map(t_game *game);

#endif