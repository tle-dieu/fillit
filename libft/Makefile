NAME = libft.a
CC = gcc
FLAG = -Wall -Werror -Wextra

AR = ar rc
RLIB = ranlib
RM = rm -f

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_atoll.c \
	  ft_iterative_power.c \
	  ft_lstfind.c \
	  ft_lstlen.c \
	  ft_print_words_tables.c \
	  ft_sort_integer_table.c \
	  ft_sqrt.c \
	  ft_strrev.c \
	  ft_strndup.c \
	  ft_strcdup.c \
	  ft_strclen.c \
	  ft_count_words.c \
	  get_next_line.c

OBJ = $(SRC:.c=.o)
INCLUDE = libft.h

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) has been created$(NC)"
	@$(RLIB) $(NAME)
	@echo "$(GREEN)$(NAME) has been indexed$(NC)"

%.o: %.c $(INCLUDE)
	@$(CC) $(FLAG) -o $@ -c $<
	@echo "$(GREEN) [\xE2\x9C\x93]     $(YELLOW) Compiling:$(NC)$<"

.PHONY: clean

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)The libft objects have been removed$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) has been removed$(NC)"

re: fclean all
