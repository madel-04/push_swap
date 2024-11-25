# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madel-va <madel-va@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/23 16:19:57 by madel-va          #+#    #+#              #
#    Updated: 2024/09/23 16:19:57 by madel-va         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB         = ar rcs
RM          = rm -f
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g
NAME        = push_swap
LIB_NAME    = push_swap.a

SRC         = control_erros.c \
              ft_split.c \
              init.c \
              main.c \
              ps_init.c \
              push.c \
              reverse_rotate.c \
              rotate_both.c \
              rotate.c \
              stack_utils.c \
              swap.c \
              three_sort.c

OBJ         = $(SRC:%.c=%.o)
INCLUDE     = push_swap.h

# Regla principal para crear el ejecutable
all: $(NAME)

# Genera los archivos objeto y enlaza el ejecutable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Regla para generar archivos objeto
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza de archivos objeto
clean:
	$(RM) $(OBJ)

# Limpieza completa (archivos objeto, ejecutables y librerías)
fclean: clean
	$(RM) $(NAME) $(LIB_NAME)

# Reconstrucción completa
re: fclean all

.PHONY: all clean fclean re
