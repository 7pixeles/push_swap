# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+ +:+         +:+      #
#    By: ayucarre <ayucarre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 12:30:15 by ayucarre          #+#    #+#              #
#    Updated: 2025/11/24 18:26:51 by ayucarre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		ft_strdup.c \
			ft_isalpha.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_atoi.c \
			ft_striteri.c \
			ft_bzero.c \
			ft_memchr.c \
			ft_strjoin.c \
			ft_calloc.c \
			ft_memcmp.c \
			ft_strlcat.c \
			ft_isalnum.c \
			ft_memcpy.c \
			ft_strlcpy.c \
			ft_memmove.c \
			ft_strlen.c \
			ft_isascii.c \
			ft_memset.c \
			ft_strmapi.c \
			ft_isdigit.c \
			ft_printf.c \
			ft_strncmp.c \
			ft_putchar.c \
			ft_strnstr.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_strrchr.c \
			ft_putendl_fd.c \
			ft_strtrim.c \
			ft_putnbr.c \
			ft_substr.c \
			ft_putnbr_fd.c \
			ft_tolower.c \
			ft_putstr.c \
			ft_toupper.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			pf_ptr.c \
			ft_putnbr_base.c \
			ft_size_new_line.c \
			ft_unsign_putnbr.c \
			get_next_line.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c

NAME =	libft.a

OBJ	=	$(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = rcs

RM = rm -rf

all: $(NAME)

$(NAME):$(OBJ)
		$(AR) $(ARFLAGS) $(NAME) $(OBJ)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re