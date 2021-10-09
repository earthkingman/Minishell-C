# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ji-park <ji-park@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 21:13:53 by ji-park           #+#    #+#              #
#    Updated: 2021/10/08 21:13:56 by ji-park          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
#CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
CC = gcc

LIBFT = libft.a
LIBFT_DIR = lib/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
CFLAGS += -I $(LIBFT_DIR)
CFLAGS += -I ./inc/
LDFLAGS="-L/Users/$(USER)/.brew/opt/readline/lib"
CPPFLAGS="-I/Users/$(USER)/.brew/opt/readline/include"

FILES = parse_env \
		convert_quotes \
		env_util \
		quotes_util \
		parse_execute \
		redirection_util \
		parse_error_check \
		free_util \
		execute \
		make_cmd \
		token_util \
		rd_util \
		ft_cd \
		ft_unset \
		ft_export \
		ft_exit \
		ft_export2 \
		child_execute \
		ft_echo \
		ft_pwd \
		ft_env \
		etc \
		etc_util \
		my_signal \
		herodoc

SRCS = $(addprefix srcs/, $(addsuffix .c, $(FILES))) 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./lib/libft
	$(CC) $(CFLAGS) -o $(NAME) main.c $(SRCS) $(LIBFT_FLAGS) -lreadline $(LDFLAGS) $(CPPFLAGS) -lncurses
	
clean :
	$(MAKE) clean -C ./lib/libft
	rm -rf $(SURP)
	rm -f $(OBJS) $(C_OBJS)

fclean :
	$(MAKE) fclean -C ./lib/libft
	rm -f $(OBJS) $(C_OBJS) $(NAME)
	
re : fclean all

.PHONY: clean fclean all re bonus
