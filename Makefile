# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayua <ayua@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 12:30:15 by ayucarre          #+#    #+#              #
#    Updated: 2025/11/29 11:21:40 by ayua             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# COLORS
RESET   = \033[0m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m

#MAKEFLAGS = --no-print-directory
MAKEFLAGS = --silent

OK      = $(GREEN)[OK]$(RESET)
BUILD   = $(BLUE)[BUILD]$(RESET)
CLEAN   = $(YELLOW)[CLEAN]$(RESET)

# PROJECT CONFIG
NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -MMD -MP
SANITIZE = -g3 -fsanitize=address

LIBFT_PATH	= ./lib/libft
HEADER_LIBFT = -I $(LIBFT_PATH)
HEADER_PS = -I include
LIBFT	= $(LIBFT_PATH)/libft.a
LIBS	= $(LIBFT)

# AUTO SRC + OBJ SETUP
SRCS_DIR	= srcs
OBJ_DIR		= obj

# TODO En código final, poner las direcciones de todos los archivos
SRCS	= $(wildcard $(SRCS_DIR)/*.c)
OBJS	= $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS	= $(OBJS:.o=.d)

# TARGETS
all:	$(NAME)

# LIBFT
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)
	@echo "$(OK) $(GREEN)libft compiled.$(RESET)"

# OBJ FILES
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(SANITIZE) $(HEADER_LIBFT) $(HEADER_PS) -c $< -o $@
	@echo "$(BUILD) $<"

# MAKE
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(SANITIZE) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(OK) $(GREEN)$(NAME) compiled.$(RESET)"

# CLEAN
clean:
	rm -rf $(OBJS) $(DEPS)
	@rm -rf $(OBJ_DIR)
	@echo "$(CLEAN) $(YELLOW).o $(NAME) removed.$(RESET)"

fclean:	clean
	rm -rf $(NAME) $(DEPS)
	$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "$(CLEAN) $(YELLOW)$(NAME) removed.$(RESET)"

re:		fclean all

-include $(DEPS)

.PHONY:	all clean fclean re