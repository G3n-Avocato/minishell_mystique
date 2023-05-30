# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 17:11:07 by lamasson          #+#    #+#              #
#    Updated: 2023/05/26 15:37:24 by lamasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## COLORS ##########

_END="\033[0m"
_RED="\033[0;31m"
_GREEN="\033[0;32m"
_YELLOW="\033[0;33m"
_CYAN="\033[0;36m"

########## ARGUMENTS ##########

NAME		= minishell
CXX			= gcc
CXXFLAGS	= -Wall -Werror -Wextra -g

########## SOURCES ##########

SRC_DIR		= src
OBJ_DIR		= obj
BIN_DIR		= bin

MAKEFLAGS	+= --no-print-directory
SRC			= src/ft_check_builtins.c \
			src/ft_exec.c \
			src/ft_find_val_env.c \
			src/ft_get_path_cmd.c \
			src/ft_init_tab_env.c \
			src/ft_maj_tab_env.c \
			src/ft_normalize_line.c \
			src/ft_parsing_cmd.c \
			src/ft_pipex.c \
			src/ft_readline.c \
			src/ft_split_minishell.c \
			src/ft_strjoin_path.c \
			src/ft_utils.c \
			src/main.c \
			src/parsing_redirection.c \
			src/parsing_right_file.c \
			src/built/ft_cd.c \
			src/built/ft_echo.c \
			src/built/ft_env.c \
			src/built/ft_exit.c \
			src/built/ft_export.c \
			src/built/ft_export_utils.c \
			src/built/ft_pwd.c \
			src/built/ft_unset.c

OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT		= libft
INC			= -Iinc

########## RULES ##########

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo $(_GREEN)Compiling $(OBJ)...$(END)
	@echo $(_GREEN)Compiling libft
	@$(MAKE) bonus -C $(LIBFT)
	@$(CXX) $(CXXFLAGS) -L $(LIBFT) -o $(NAME) $(OBJ) -lreadline -l:libft.a

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@echo $(_CYAN)Compiling $<...$(END)
	@$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	@echo $(_YELLOW)Cleaning $(OBJ)...$(END)
	@rm -rf $(OBJ_DIR)
	@echo $(-_YELLOW)Cleaning libft
	@$(MAKE) -s -C $(LIBFT) clean

fclean: clean
	@echo $(_RED)Cleaning $(NAME)...$(END)
	@rm -rf $(NAME)
	@echo $(_RED)Cleaning libft.a
	@$(MAKE) -s -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
