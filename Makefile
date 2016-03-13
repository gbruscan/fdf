#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbruscan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/20 18:10:38 by gbruscan          #+#    #+#              #
#    Updated: 2016/01/20 18:24:38 by gbruscan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =  	fdf

CC =		gcc

SRCS =		srcs/main.c \
		srcs/get_next_line.c \
		srcs/check.c \
		srcs/color_check.c \
		srcs/window.c \
		srcs/map.c

CFLAGS =	-Wall -Wextra -Werror -g
CFLAGS +=	-I./includes -I/usr/X11/include

OBJ =		$(SRCS:.c=.o)

LIBFLAGS =	-L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

LIB =		libft.a

LPATH =		libft

LIBINC =	-L$(LPATH) -lft -I /usr/X11/include/ -I minilibx_macos/

LIBH =		-I$(LPATH)

all :		$(NAME)

$(NAME) :	$(LPATH) $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(LIBINC) $(LIBFLAGS) -o $(NAME)

$(LIB) :
			make -C $(LPATH)

$(LPATH) :	$(LIB)

clean :
		rm -f $(OBJ)

cleanlib :
		make clean -C $(LPATH)

fcleanlib :
		make fclean -C $(LPATH)

fclean :	fcleanlib clean
			rm -f $(NAME)

re : fclean all