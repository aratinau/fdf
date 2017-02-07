# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/02 14:59:44 by aratinau          #+#    #+#              #
#    Updated: 2015/09/29 20:03:53 by aratinau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = get_next_line.c \
	  rotate_x.c \
	  rotate_y.c \
	  rotate_z.c \
	  node.c \
	  edge.c \
	  draw.c \
	  trace.c \
	  event_mlx.c \
	  misc.c \
	  fdf.c

OBJ_PATH = ./obj/

OBJ2 = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
OBJ = $(addprefix $(OBJ_PATH),$(OBJ2))

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx_macos/
	$(CC) $(CFLAGS) libft/libft.a minilibx_macos/libmlx.a -o $(NAME) $(OBJ) \
	-lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(OBJ_PATH)%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
