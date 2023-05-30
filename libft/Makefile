# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbertet <gbertet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 20:59:05 by lamasson          #+#    #+#              #
#    Updated: 2023/04/27 18:46:40 by gbertet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= clang

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

NAME	= libft.a

SRCS	= ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_realloc.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strncmp.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strnstr.c \
	  ft_atoi.c \
	  ft_calloc.c \
	  ft_strdup.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_printf.c \
	  ft_printf_utils.c \
	  get_next_line.c \
	  get_next_line_utils.c \
	  ft_free_tab.c

SRCS_BONUS = ft_lstnew_bonus.c \
	  ft_lstadd_front_bonus.c \
	  ft_lstsize_bonus.c \
	  ft_lstlast_bonus.c \
	  ft_lstadd_back_bonus.c \
	  ft_lstdelone_bonus.c \
	  ft_lstclear_bonus.c \
	  ft_lstiter_bonus.c \
	  ft_lstmap_bonus.c

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
#	gcc -nostartfiles -shared -o libft.so $(OBJS)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME}

re:	fclean all

bonus:	${OBJS_BONUS} ${OBJS}
	ar rc ${NAME} ${OBJS_BONUS} ${OBJS}

.PHONY: all clean fclean re bonus
