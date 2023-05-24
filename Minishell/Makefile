# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/6 10:06:40 by kchatvet          #+#    #+#              #
#    Updated: 2023/05/06 07:38:09 by kanit_c          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

## check leak CFLAGS = -Wall  -Wextra -Werror -g -fsanitize=address

NAME = minishell

LIBMI = libminishell.a

SRCE = minishell.c\


#	read_input_0.c\
#	read_input_1.c\
#	history_0.c\
#	history_1.c\ 
#       Tokenize_0.c\
#	Tokenize_1.c\
#       executables_0.c\
#       executables_0.c\
#	pipe_operators_0.c\
#	pipe_operation_0.c\
#       Environment_0.c\
#	Environment10.c\	

OBJ_DIR = Obj/

LIBFT_DIR = libft
LIBFT_LINK = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT_LINK)
	@cc $(FLAGS) $(SRCE) -I./  -L./ -lminishell -o $(NAME)
	@echo "  ●   ●"
	@echo "   █   █"
	@echo "    █   █"
	@echo "    █   █"
	@echo "    ███            █████"　　　
	@echo "  █▒░░█         ██▓▒▒▓██ ☆"
	@echo " █▒░●░░█    ██▓▒██▓▒▒▓█　　 ★"
	@echo " █░█▒░░██  ██▓▒██▓▒░▒▓█"
	@echo "  ██▒░░██ ██▓▒░██▓▒░▒▓█ 　　　★"
	@echo "     █▒░██ ██▓▒░░ ████▓█"
	@echo "    █▒░██  ██▓▓▒▒░░░██ 　 ★★"
	@echo "     █▒░██   ████████████"
	@echo "      █▒░█▒▒▒▒▒▒▒▒▒▒▒▒█"
	@echo "       ██████████████████.•°*”˜҈.•°*”˜҈."
	@echo " "
	
	
$(LIBFT_LINK):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_LINK) $(LIBMI)
	@mkdir -p $(OBJ_DIR)
	@cc $(FLAGS) -c $(SRCE) -I./
	@ar rcs $(LIBMI) *.o
	@mv *.o $(OBJ_DIR)
	@echo " "
	@echo " Make libminishell.a "
	@echo " "
	
bonus:
	@echo "Hello Bonus"
	
clean:
	make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)
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
