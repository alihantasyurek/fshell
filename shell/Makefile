# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atasyure <atasyure@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 05:24:00 by atasyure          #+#    #+#              #
#    Updated: 2024/03/14 20:14:37 by atasyure         ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minishell
CC		:= gcc
INCLUDE	:= ./includes
CFLAGS	:= -ggdb -I $(INCLUDE) -I ./libft
LIBFT	= libft
FLAGS	= -Wall -Wextra -Werror -g

SRC		:= builtin5.c \
			builtin.c \
			builtin1.c \
			builtin2.c \
			builtin3.c \
			builtin4.c \
			check.c \
			check_utils.c \
			dup2_fd.c \
			exec_free.c \
			exec_free2.c \
			exec.c \
			execve.c \
			execve1.c \
			expander.c \
			expander2.c \
			create_files_utils.c \
			create_files.c \
			heredoc_utils.c \
			heredoc.c \
			lexer.c \
			env.c \
			main.c \
			init.c \
			parser.c \
			parser_utils.c \
			signal.c \
			expander_utils.c \
			utils.c \
			exec_utils.c \
			free.c


OBJ		:= $(SRC:%.c=$(OBJDIR)%.o)

RED=\033[0;31m
GREEN=\033[0;32m
NC=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(RED)Procces still continue...$(NC)"
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@$(CC) $(FLAGS) $(CFLAGS) $(OBJ) libft.a -lreadline -o $(NAME)
	@echo "$(GREEN)Done!$(NC)"

$(OBJDIR)%.o: %.c
	@$(CC) $(FLAGS) $(CFLAGS) -c $< -o $@

m:
	@echo "1. hedef make re"
	@echo "2. hedef make fclean"
	@read -p "Seçiminizi yapın: " secim; \
	case $$secim in \
		1) make re ;; \
		2) make fclean ;; \
		*) echo "Geçersiz seçim" ;; \
	esac

c: clean
clean:
	@echo "Cleaning..."
	@make clean -C $(LIBFT)
	@rm -rf libft.a
	@rm -rf $(OBJ)
	@echo "$(GREEN)Done!$(NC)"

f: fclean
fclean:
	@echo "Cleaning with name..."
	@make fclean -C $(LIBFT)
	@rm -rf libft.a
	@rm -rf $(OBJ)
	@rm -f $(NAME)

r: re
re:	fclean all

.PHONY: all clean fclean re
