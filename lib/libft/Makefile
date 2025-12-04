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

# ===========================
#          COLORS
# ===========================
RESET	= \033[0m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m

OK		= $(GREEN)[OK]$(RESET)
CLEAN	= $(YELLOW)[CLEAN]$(RESET)

# ===========================
#        LIBFT CONFIG
# ===========================
NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP

SRC_DIR		= srcs
INC_DIR		= .
OBJ_DIR		= obj
SRC			=	ft_atoi.c \
				ft_lstiter.c \
				ft_putnbr_base.c \
				ft_strmapi.c \
				ft_bzero.c \
				ft_lstlast.c \
				ft_putnbr.c \
				ft_strncmp.c \
				ft_calloc.c \
				ft_lstmap.c \
				ft_putnbr_fd.c \
				ft_strnstr.c \
				ft_isalnum.c \
				ft_lstnew.c \
				ft_putstr.c \
				ft_strrchr.c \
				ft_isalpha.c \
				ft_lstsize.c \
				ft_putstr_fd.c \
				ft_strtrim.c \
				ft_isascii.c \
				ft_memchr.c \
				ft_size_new_line.c \
				ft_substr.c \
				ft_isdigit.c \
				ft_memcmp.c \
				ft_split.c \
				ft_tolower.c \
				ft_isprint.c \
				ft_memcpy.c \
				ft_strchr.c \
				ft_toupper.c \
				ft_isspace.c \
				ft_memmove.c \
				ft_strdup.c \
				ft_unsign_putnbr.c \
				ft_itoa.c \
				ft_memset.c \
				ft_striteri.c \
				get_next_line.c \
				ft_lstadd_back.c \
				ft_printf.c \
				ft_strjoin.c \
				pf_ptr.c \
				ft_lstadd_front.c \
				ft_putchar.c \
				ft_strlcat.c \
				ft_lstclear.c \
				ft_putchar_fd.c \
				ft_strlcpy.c \
				ft_lstdelone.c \
				ft_putendl_fd.c \
				ft_strlen.c \

SRCS		= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS		= $(OBJS:.o=.d)

AR			= ar rcs

# ===========================
#     PROGRESS BAR CONFIG
# ===========================
TOTAL_SRCS	= $(words $(SRCS))
COUNTER_FILE = .counter

define progress_bar
	@count=$$(cat $(COUNTER_FILE)); \
	perc=$$((100 * $$count / $(TOTAL_SRCS))); \
	bars=$$((perc / 5)); \
	bar=$$(printf "%0.s#" $$(seq 1 $$bars)); \
	printf "\rCompiling: [%-20s] %3s%%" "$$bar" "$$perc";
endef

# ===========================
#          TARGETS
# ===========================
all: $(NAME)

$(NAME): reset_counter $(OBJ_DIR) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@printf "\r$(OK) $(NAME) built.$(RESET)\n"
# ---------- CREATE OBJ DIR ----------

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# ---------- OBJ BUILD ----------
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@ >/dev/null 2>&1
	@echo $$(( $$(cat $(COUNTER_FILE)) + 1 )) > $(COUNTER_FILE)
	$(call progress_bar)


# ---------- COUNTER MGMT ----------
reset_counter:
	@echo 0 > $(COUNTER_FILE)

# ---------- CLEAN ----------
clean:
	@rm -rf $(OBJ_DIR) $(COUNTER_FILE)
	@echo "$(CLEAN) objects removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CLEAN) $(NAME) removed.$(RESET)"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re reset_counter
