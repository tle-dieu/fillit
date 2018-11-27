NAME = fillit
CC = gcc
FLAG = -Wall -Werror -Wextra
LDFLAG = -L./$(LIBDIR) -lft

RM = rm -f

SRC = reader.c \
	  map.c \
	  main.c \
	  tetri.c \
	  free.c

OBJ = $(SRC:.c=.o)

LIBDIR = libft
LIBFT = $(LIBDIR)/libft.a
INCLUDE = fillit.h

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $@ $(LDFLAG) $^
	@echo "$(GREEN)$(NAME) has been created$(NC)"

$(LIBFT):
	@(cd $(LIBDIR) && $(MAKE))

%.o: %.c $(INCLUDE)
	@$(CC) $(FLAG) -I $(LIBDIR) -o $@ -c $<
	@echo "$(GREEN) [\xE2\x9C\x93]     $(YELLOW) Compiling:$(NC)$<"

clean:
	@(cd $(LIBDIR) && $(MAKE) $@)
	@$(RM) $(OBJ)
	@echo "$(RED)The gnl objects have been removed$(NC)"

fclean:
	@(cd $(LIBDIR) && $(MAKE) $@)
	@$(RM) $(OBJ) $(NAME)
	@echo "$(RED)The gnl objects have been removed$(NC)"
	@echo "$(RED)$(NAME) has been removed$(NC)"

re: fclean all

.PHONY: clean fclean
