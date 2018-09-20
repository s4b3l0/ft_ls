# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 09:55:53 by sankosi           #+#    #+#              #
#    Updated: 2018/09/01 12:07:42 by sankosi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror -c -I includes/
FILES =	ft_isprint.c \
		ft_lstnew.c \
		shorthandler.c \
		ft_lstadd.c \
		ft_striter.c \
		ft_strsplit.c \
		ft_strlcat.c \
		ft_isspace.c \
		ft_toupper.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_strdel.c \
		ft_strnequ.c \
		ft_itoa.c \
		ft_strncat.c \
		ft_memdel.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_putnbr_fd.c \
		ft_strdup.c	\
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_putstr.c \
		ft_memchr.c \
		ft_strequ.c \
		ft_memalloc.c \
		ft_strsub.c \
		ft_atoi.c \
		ft_memset.c \
		ft_putstr_fd.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_bzero.c \
		ft_putchar.c \
		ft_strcat.c \
		ft_strlen.c \
		ft_tolower.c \
		ft_isalnum.c \
		ft_putchar_fd.c \
		ft_strchr.c \
		ft_strncmp.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_isalpha.c \
		ft_putendl.c \
		ft_strclr.c \
		ft_strncpy.c \
		ft_memcmp.c \
		ft_isascii.c \
		ft_putendl_fd.c \
		ft_strcmp.c \
		ft_strnew.c \
		ft_isdigit.c \
		ft_putnbr.c \
		ft_strcpy.c \
		ft_strrchr.c \
		ft_printchar.c \
		ft_printf.c \
		ft_printinteger.c \
		ft_printoct.c \
		ft_printstr.c \
		ft_printx.c \
		ft_putpad.c \
		ft_putunsigned.c \
		initialize.c \
		long_handler.c \
		ft_lstpushback.c \
		ft_printmax.c \
		ft_max_handler.c \
		ft_printptr.c \

OBJ=$(FILES:.c=.o)

.SILENT:

all:$(NAME)
$(NAME):$(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)
	#printf '\033[4m'
	printf '\033[36m[ ✔ ] %s\n\033[0m' "Created libftprintf.a]"
%.o : %.c
	gcc $(FLAGS) $<
	printf '\033[33m[ ✔ ] %s\n\033[0m' "$<"
clean:
	rm -f $(OBJ)
	printf '\033[34m[ ✔ ] %s\n\033[0m' "Cleaned Libft"
fclean: clean
	rm -f $(NAME)
	printf '\033[35m[ ✔ ] %s\n\033[0m' "Fclean Libft"
re: fclean all
.PHONY: clean fclean re all
