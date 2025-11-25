# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 12:30:15 by ayucarre          #+#    #+#              #
#    Updated: 2025/11/20 11:28:43 by ayucarre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -MMD -MP
SANITIZE = -g3 -fsanitize=address

LIBFT_PATH	= ./lib/libft

HEADERS	= -I $(LIBFT_PATH)
LIBFT	= $(LIBFT_PATH)/libft.a

LIBS	= $(LIBFT)

SRCS	= srcs/push_swap.c
OBJS	= $(SRCS:.c=.o)
DEPS	= $(OBJS:.o=.d)

all:	$(NAME)

# ---------- LIBFT ----------
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# ---------- OBJ FILES ----------
%.o: %.c
	$(CC) $(CFLAGS) $(SANITIZE) $(HEADERS) -c $< -o $@

# ---------- MAKE ----------
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SANITIZE) $(OBJS) $(LIBS) -o $(NAME)

# ---------- CLEAN ----------
clean:
	rm -rf $(OBJS) $(DEPS)

fclean:	clean
	rm -rf $(NAME) $(DEPS)
	$(MAKE) -C $(LIBFT_PATH) fclean

re:		fclean all

-include $(DEPS)

.PHONY:	all clean fclean re 
