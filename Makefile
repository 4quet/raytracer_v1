#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/06/12 16:29:17 by lfourque          #+#    #+#             *#
#*   Updated: 2015/06/12 16:41:27 by lfourque         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = rtv1

SRC = main.c\
	  hook.c\
	  cone.c\
	  draw.c\
	  utils.c\
	  plane.c\
	  color.c\
	  vector.c\
	  vector2.c\
	  sphere.c\
	  camera.c\
	  cylinder.c\
	  raytrace.c\
	  transform.c\
	  obj_value.c\
	  line_value.c\
	  get_shadow.c\
	  scene_file.c\
	  get_next_line.c

SRC_DIR = $(addprefix src/, $(SRC))

OBJ = $(SRC:.c=.o)

OBJ_DIR = $(addprefix obj/, $(OBJ))

LIB = -framework OpenGL -framework Appkit -L /usr/local/lib -lmlx

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(SRC_DIR) inc/rtv1.h
	@echo "Compiling RTV1..."
	@make -C libft/
	@gcc -Wall -Wextra -Werror -I inc/ -I libft/includes -c $(SRC_DIR)
	@gcc -o $(NAME) -I inc/ libft/libft.a $(LIB) $(OBJ)
	@/bin/rm -rf obj/
	@mkdir obj
	@mv $(OBJ) obj/
	@echo "OK"

clean:
	@/bin/rm -f $(OBJ_DIR)
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf obj/
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
