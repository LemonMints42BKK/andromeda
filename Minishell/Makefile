# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/6 10:06:40 by kchatvet          #+#    #+#              #
#    Updated: 2023/06/19 09:05:22 by kchatvet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	=	-Wall -Wextra -Werror

## check leak CFLAGS = -Wall  -Wextra -Werror -g -fsanitize=address

NAME	=	minishell

LIBMI	=	libminishell.a

SRCE	=	minishell.c\
			./src/history.c\
			./src/prompt.c\
			./src/signal.c\
			./src/env_getenv.c\
			./src/env_manage.c\
			./src/utiles1.c

# ./src/tokenize.c\
#       Tokenize_0.c\
#	Tokenize_1.c\
#       executables_0.c\
#       executables_0.c\
#	pipe_operators_0.c\
#	pipe_operation_0.c\
#       Environment_0.c\
#	Environment10.c\

OBJ_DIR = obj/

OBJ = $(SRCE:.c=.o)

LIBFT_DIR = libft
LIBFT_LINK = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_LINK) $(LIBMI)
	@ar rcs $(LIBMI) *.o

	@echo " "
	@echo " Make libminishell.a "
	@echo " "
	@cc $(FLAGS) $(OBJ) -I./  -L./ -lminishell -lreadline -o $(NAME)
#	@mv *.o $(OBJ_DIR)
	@echo " "
	@echo "    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⡴⠶⠞⠛⠛⠉⠉⠉⠉⠉⠉⠛⠛⠶⢦⣄⡀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⣶⣾⠿⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠈⠛⢦⡀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⠶⢛⣩⠶⠛⠉⠀⠀⠀⣀⣤⡴⠶⠚⠛⠛⠛⠉⠛⠛⠛⢶⡟⠉⢻⡄⠀⠀⠀⠈⢻⡄"
	@echo "⠀⠀⠀⠀⠀⠀⠀⣠⡴⠟⢉⣠⠶⠋⠁⠀⠀⣠⡴⠞⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠷⡤⠾⣇⠀⠀⠀⠀⠀⣿"
	@echo "⠀⠀⠀⠀⣠⡴⠛⠁⣀⡴⠛⠁⠀⢀⣠⠶⠛⠁⠀⠀⠀⣀⣠⡤⠶⠒⠛⠛⠛⠛⠛⠶⣤⡀⠀⠀⠀⢹⡆⠀⠀⠀⠀⢸"
	@echo "⠀⢀⣴⠟⠁⠀⣠⡾⠋⠀⠀⢀⡴⠛⠁⠀⢰⠞⠳⡶⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣷⠀⠀⠀⢈⡇⠀⠀⠀⠀⣾"
	@echo "⢴⠟⠁⠀⢀⡼⠋⠀⠀⢀⡴⠋⠀⠀⠀⣠⡾⠷⠶⠇⢀⣠⣤⠶⠖⠲⢶⣄⠀⠀⠀⠀⠀⡿⠀⠀⠀⢸⡇⠀⠀⠀⢰⡏"
	@echo "⠀⠀⠀⣰⠟⠀⠀⠀⣴⠏⠀⠀⠀⣠⠞⠉⠀⠀⣠⡶⠋⠁⠀⠀⠀⠀⢀⡿⠀⠀⠀⠀⣼⠃⠀⠀⢀⡟⠂⠀⠀⢠⡟⠀"
	@echo "⠀⢀⣼⠋⠀⠀⢀⡾⠁⠀⠀⢠⡞⠁⠀⠀⢠⡾⠁⠀⠀⠀⠀⣀⣀⣠⡾⠁⠀⠀⣠⡾⠁⠀⠀⢠⡞⠁⠀⠀⣰⠟⠀⠀"
	@echo "⠀⣾⠃⠀⢠⡟⠛⣷⠂⠀⢠⡟⠀⠀⠀⠀⢾⡀⠀⠀⠀⠀⣸⣏⣹⡏⠀⠀⣠⡾⠋⠀⠀⢀⣴⠏⠀⠀⢀⡼⠋⠀⠀⠀"
	@echo "⣸⠇⠀⠀⠈⢻⡶⠛⠀⠀⣿⠀⠀⠀⠀⠀⠈⠛⠲⠖⠚⠋⠉⠉⠉⣀⣤⠞⠋⠀⠀⢀⣴⠟⠁⠀⠀⣰⠟⠁⠀⣴⠆⠀"
	@echo "⣿⠀⠀⠀⠀⢸⡇⠀⠀⠀⢻⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⠶⠛⠉⣀⣀⡀⣀⡴⠟⠁⠀⢀⣤⠞⠁⢀⣴⠟⠁⠀⠀"
	@echo "⣿⠀⠀⠀⠀⠘⣧⠀⠀⠀⠀⠙⠳⠶⠤⣤⠤⠶⠶⠚⠋⠉⠀⠀⠀⡟⠉⠈⢻⡏⠀⠀⣀⡴⠛⠁⣠⡶⠋⠁⠀⠀⠀⠀"
	@echo "⢻⡀⠀⠀⠀⠀⠘⢷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⠶⠻⢦⣤⠟⣀⣤⠞⢋⣠⡴⠛⠁⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠈⢿⣄⠀⠀⠀⠀⠀⠈⠛⠳⠶⠤⠤⠤⠤⠤⠴⠶⠒⠛⠉⠁⠀⠀⢀⣠⡴⣞⣋⣤⠶⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠙⢷⡶⠛⠳⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣴⣾⠿⠿⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠘⣧⡀⣀⣿⠦⣤⣤⣤⣤⣤⣤⠤⠶⠶⠞⠛⠋⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠈⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"

	@echo " "

#$(LIBFT_LINK): $(OBJ)
#	@make -C $(LIBFT_DIR)
#	@cp $(LIBFT_LINK) $(LIBMI)
#	@mkdir -p $(OBJ_DIR)
##	@cc $(FLAGS) -c $(OBJ) -I./
#	@ar rcs $(LIBMI) *.o
##	@mv *.o $(OBJ_DIR)
#	@echo " "
#	@echo " Make libminishell.a "
#	@echo " "

bonus:
	@echo "Hello Bonus"

clean:
	make clean -C $(LIBFT_DIR)
#	@rm -rf $(OBJ_DIR)
	@rm -f *.o src/*.o
	@echo " "
	@echo "* clean compleate "
	@echo " "

fclean: clean
	make fclean -C $(LIBFT_DIR)
	@rm -f $(LIBMI)
	@rm -f $(NAME)
	@echo " "
	@echo "* fclean compleate"
	@echo " "

re: fclean all

.PHONY: clean fclean all re
