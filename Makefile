# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggaudin- <ggaudin-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 18:55:12 by ggaudin-          #+#    #+#              #
#    Updated: 2018/04/03 22:25:13 by ggaudin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = srcs/

SRC = main.c\
	  fdf.c\
	  parse.c\
	  stock.c\
	  draw.c\
	  keyhook.c\
	  restock.c\
	  stockmap.c\
	  init.c\
	  restockb.c\
	  filliso.c\

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

INC = -I ./includes/ -I ./libft/

LIB = -L minilibx -lmlx -framework OpenGL -framework Appkit -L ./libft/ -lft

all: $(NAME)

$(NAME):  $(OBJ)
	@make -C libft/
	@gcc $(OBJ) $(INC) $(LIB) -o $(NAME)
	@echo "$(GREEN)[✓] FDF: READY!$(NC)"

%.o: $(SRC_PATH)%.c
	@gcc -c $(FLAGS) $< -o $@ $(INC)

clean:
	@rm -f $(OBJ)
	@echo "$(RED)[-] FDF: SUPPRESSION DES FICHIERS OBJETS.$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[-] FDF: SUPPRESSION DE L'EXECUTABLE.$(NC)"
	@make fclean -C ./libft/

re: fclean all

.PHONY : all re clean fclean
