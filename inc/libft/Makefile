# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvon-ah- <gvon-ah-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 14:21:25 by gvon-ah-          #+#    #+#              #
#    Updated: 2025/04/22 19:33:03 by gvon-ah-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
       ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	   ft_memmove.c ft_memset.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c \
	   ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
	   ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	   ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_striteri.c

LST = ft_lstsize.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstadd_back.c \
	  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

PLUS = ft_printf.c ft_prinft_functions_aux.c get_next_line.c get_next_line_utils.c

FUNCTIONS_HEADERS = Printf, Get_next_line

OBJS_DIR = objs

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:%.c=%.o) $(LST:.c=.o) $(PLUS:.c=.o))

NAME = libft.a

COMPRESS = ar rcs

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f	

all: $(NAME) 

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)	
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) fcount
	@$(COMPRESS) $(NAME) $(OBJS)
	@echo $(NAME) Compiled! 	

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

fcount:
	@echo "LIBTF contains $(FUNCTIONS_HEADERS), totaling $(words $(SRCS) $(LST) $(PLUS)) functions."

re: fclean all

.PHONY: all clean fclean re