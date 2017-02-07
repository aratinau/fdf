# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 13:21:39 by aratinau          #+#    #+#              #
#    Updated: 2015/09/28 14:21:19 by aratinau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memcpy.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putstr.c \
	  ft_strcat.c \
	  ft_strdup.c \
	  ft_strlen.c \
	  ft_strncat.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_strchr.c \
	  ft_strstr.c \
	  ft_memcmp.c \
	  ft_strrchr.c \
	  ft_strnstr.c \
	  ft_strcpy.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_memchr.c \
	  ft_memmove.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_isblank.c \
	  ft_strlcat.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_strdel.c \
	  ft_lstmap.c \

OBJ		= $(SRC:.c=.o)
	CC		= gcc
	CFLAGS	+= -Wall -Wextra -Werror

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) a.out

re: fclean $(NAME)
