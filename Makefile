# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 14:57:14 by mdeville          #+#    #+#              #
#    Updated: 2018/03/14 14:43:01 by mdeville         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol
CC=clang
CFLAGS=-Wall -Wextra -Werror -O3
INCLUDES=-Iincludes/ -Ilibft/includes/
LIBDIR=libft/
LDFLAGS=-lpthread -lmlx -framework OpenGL -framework AppKit

LIB=$(addprefix $(LIBDIR), libft.a)
SRC=	srcs/ft_graphics/init.c \
		srcs/ft_graphics/del_image.c \
		srcs/ft_graphics/del_mlx.c \
		srcs/ft_graphics/new_image.c \
		srcs/ft_graphics/clear_image.c \
		srcs/ft_graphics/put_pixel.c \
		srcs/ft_graphics/put_line.c \
		srcs/ft_graphics/init_hooks.c \
		srcs/ft_graphics/exit_x.c \
		srcs/print_x.c \
		srcs/key_hook.c \
		srcs/mouse_press.c \
		srcs/mouse_hook.c \
		srcs/iterate.c \
		srcs/mandelbrot.c \
		srcs/julia.c \
		srcs/main.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(LIB):
	$(MAKE) -j8 -C $(LIBDIR)

%.o: %.c includes/fractol.h includes/ft_graphics.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $@ $(LIB) $(LDFLAGS)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean
	$(MAKE)

.PHONY: re fclean clean all
