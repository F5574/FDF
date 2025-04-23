# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gisrael <gisrael@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 16:40:24 by gvon-ah-          #+#    #+#              #
#    Updated: 2025/04/23 19:15:02 by gisrael          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_C = fdf.c 

NAME = fdf

LIBFT = $(LIBFT_DIR)/libft.a

LIBFT_DIR = ./inc/libft

MLX = $(MLX_DIR)/libmlx.a

MLX_DIR = minilibx-linux

COMPRESS = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

SRCS_DIR = srcs/

OBJS_DIR = objs/

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_C))

OBJS = $(addprefix $(OBJS_DIR), $(SRCS_C:.c=.o))

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(NAME): $(LIBFT) $(OBJS) $(MLX)
	@$(CC) $(CFLAGS) $(NAME) $(OBJS) $(LIBFT) $(MLX) lm -lz -lXext -lX11 -o 
	@echo $(NAME) Compiled!

$(MLX):
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory
	@echo Clean objs!

fclean: clean
	@$(RM) $(NAME) fdf
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo Clean all!

re: fclean all

.PHONY: all fclean clean re