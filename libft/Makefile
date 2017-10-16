# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/08 18:26:36 by lfourque          #+#    #+#              #
#    Updated: 2015/10/27 15:03:51 by lfourque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	   ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c\
	   ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c\
	   ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
	   ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c\
	   ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c\
	   ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
	   ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c\
	   ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c\
	   ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c\
	   ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c\
	   ft_lstmap.c ft_intlen.c ft_putnchar.c ft_str_tolower.c ft_uintlen.c\
	   ft_uitoa.c ft_imaxtoa.c ft_imaxlen.c ft_uimaxtoa.c ft_uimaxlen.c\
	   ft_strinsert.c
SRC_DIR = $(addprefix src/, $(SRC))
OBJ = $(SRC:.c=.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(SRC_DIR) includes/libft.h
	@echo "Compiling libft..."
	@gcc -Wall -Wextra -Werror -c $(SRC_DIR) -I includes/
	@ar rc $(NAME) $(OBJ)
	@rm -rf obj/
	@mkdir obj/
	@mv $(OBJ) obj/
	@ranlib $(NAME)
	@echo "OK"

clean:
	@/bin/rm -rf obj/

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
