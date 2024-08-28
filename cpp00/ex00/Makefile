NAME	=	megaphone

SRC		=	megaphone.cpp

FLAGS	=	-Werror -Wall -Wextra -std=c++98

all:		$(NAME)

$(NAME): $(SRC)
	@echo "$(BLUE)Compiling $(NAME).$(RESET)"
	c++	$(FLAGS) $(SRC) -o $(NAME)

clean:
	@echo "$(YELLOW)There's nothing to clean, try fclean.$(RESET)"

fclean:
	if [ -e $(NAME) ] ; then \
		echo "$(RED)Removed executable $(NAME).$(RESET)"; \
		rm $(NAME); \
	else \
		echo "$(YELLOW)No executable to remove.$(RESET)"; \
	fi

re: fclean $(NAME)

.SILENT:

.PHONY: all re clean fclean

RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
BLUE	=	\033[1;34m
RESET	=	\033[0m
BOLD	=	\033[1m