# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:38:13 by lvirgini          #+#    #+#              #
#    Updated: 2021/12/02 15:26:29 by eassouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#	 VARIABLES		#
# ----------------- #

NAME =		philo

OBJ_DIR =	obj/
INC_DIR =	includes/
SRC_DIR =	$(shell find srcs -type d)

SRC		= 	get_time.c

OBJ 	=	$(addprefix $(OBJ_DIR),$(SRC:%.c=%.o))
HEADERS = 	$(foreach dir, $(INC_DIR), $(wildcard $(dir)/*.h))

vpath %.c $(foreach dir, $(SRC_DIR)/, $(dir):)
vpath %.h $(foreach dir, $(INC_DIR)/, $(dir):)

# ----------------- #
#	 COMPILATION	#
# ----------------- #

CC 		=	gcc

CFLAG 	= 	-Wall -Wextra -Werror
IFLAG 	= 	$(foreach dir, $(INC_DIR), -I $(dir))

# ----------------- #
#	  FUNCTIONS		#
# ----------------- #

$(OBJ_DIR)%.o: %.c $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			@echo "\033[32mCompilation de ... $(foreach file, $< , $(notdir $<))"
			@$(CC) $(CFLAG) $(IFLAG) -o $@ -c $<

$(NAME):	$(OBJ)
			@$(CC) $(CFLAG) $(IFLAG) $(OBJ) -o $@
			@echo "\n*     Compilation $(NAME)     *\t   \033[32;1m--> \033[4;5mComplete\033[0m"

all:		$(NAME)

# ----------------- #
# 		CLEAN		#
# ----------------- #

clean:
			rm -rf $(OBJ_DIR)

fclean: clean
			rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re