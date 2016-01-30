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

NAME =  fdf

CC =	gcc

CFLAGS = -Wall -Wextra -Werror 

FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

LIBDIR = libft/

SRCS =	main.c \
		get_next_line.c \
		check.c \
		color_check.c \
		map.c
OBJ =	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
		make -C $(LIBDIR)
		$(CC) $(CFLAGS) $(FRAMEWORK) -o $(NAME) $(OBJ) -L $(LIBDIR) -lft

%.o:	%.c
		$(CC) $(CFLAGS) -o $@ -c $<

clean:
		rm -rf $(OBJ)
		make -C $(LIBDIR) clean

fclean:	clean
		rm -rf $(NAME)
		make -C $(LIBDIR) fclean

re:		fclean all
