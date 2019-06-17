# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 08:23:40 by achauvea          #+#    #+#              #
#    Updated: 2018/08/29 16:28:32 by mnkebeny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls.a

SRC		=	flags.c list.c allfiles.c lrecursive.c recursive.c \
			reverse.c lreverse.c chmod.c ft_time.c ft_ltime.c \
 
OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@gcc -g $(CFLAGS) -o ft_ls main.c $(NAME) libft/libft.a

all: $(NAME)

clean:
	@make clean -C libft/
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME) $(OBJ)
	@rm -rf ft_ls

re: fclean $(NAME)
