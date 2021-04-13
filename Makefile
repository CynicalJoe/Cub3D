SRCS=	srcs/main.c srcs/window.c srcs/parsing.c srcs/get_next_line.c srcs/get_next_line_utils.c srcs/parsing_ressources.c srcs/raycasting.c srcs/img.c srcs/map_checking.c srcs/error.c srcs/free.c srcs/init.c srcs/color.c srcs/mouvement.c

INCLUDE= include/cub3d.h

OBJS= ${SRCS:.c=.o}

CC = gcc

CFLAGS= -Wall -Wextra -Werror -I$(INCLUDE)

MLX= libmlx.dylib

LIBFT= libft.a

LFLAGS=  -I /mlx/mlx.h $(MLX) -lmlx -framework OpenGL -framework AppKit 

NAME= cub3D

RM= rm -f 

$(NAME):	$(OBJS)
			@make -s -C ./srcs/libft
			@make -s -C ./mlx_linux
			@mv ./srcs/libft/libft.a .
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L mlx_linux -lmlx -lm -lbsd -lX11 -lXext $(LIBFT)

%.o:	%.c
		 $(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:	$(NAME)

clean:
		$(RM) $(OBJS)
		@make clean -s -C ./srcs/libft
		@make clean -s -C ./mlx

fclean:
		$(RM) $(OBJS) $(NAME) $(MLX) $(LIBFT)
		@make clean -s -C ./mlx
		@make fclean -s -C ./srcs/libft

re : fclean all