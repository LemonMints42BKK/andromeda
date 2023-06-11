# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchatvet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 19:53:50 by kchatvet          #+#    #+#              #
#    Updated: 2022/10/05 21:19:58 by kchatvet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRCE = ft_isalpha.c\
       ft_isdigit.c\
       ft_isalnum.c\
       ft_isascii.c\
       ft_isprint.c\
       ft_strlen.c\
       ft_memset.c\
       ft_bzero.c\
       ft_memcpy.c\
       ft_memmove.c\
       ft_strlcpy.c\
       ft_strlcat.c\
       ft_toupper.c\
       ft_tolower.c\
       ft_strchr.c\
       ft_strrchr.c\
       ft_strncmp.c\
       ft_memchr.c\
       ft_memcmp.c\
       ft_strnstr.c\
       ft_atoi.c\
       ft_calloc.c\
       ft_strdup.c\
       ft_substr.c\
       ft_strjoin.c\
       ft_strtrim.c\
       ft_split.c\
       ft_itoa.c\
       ft_strmapi.c\
       ft_striteri.c\
       ft_putchar_fd.c\
       ft_putstr_fd.c\
       ft_putendl_fd.c\
       ft_putnbr_fd.c\
       ft_printf.c\
       ft_printf_format.c\
       ft_printf_utils1.c\
       ft_printf_utils2.c\
       ft_printf_utils3.c\
       ft_printf_utils4.c\
       ft_printf_flags1_bonus.c\
       ft_printf_flags2_bonus.c\
       get_next_line_bonus.c\
       get_next_line_utils_bonus.c

BONUS = ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c

all:$(NAME)

$(NAME):$(SRCE)
	@gcc $(FLAGS) -c $(SRCE) -I./
	@ar rcs $(NAME) *.o

bonus:
	@gcc $(FLAGS) -c $(SRCE) $(BONUS) -I./
	@ar rcs $(NAME) *.o

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
