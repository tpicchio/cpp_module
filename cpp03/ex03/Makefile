# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 10:02:17 by tpicchio          #+#    #+#              #
#    Updated: 2024/09/14 10:02:49 by tpicchio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamondTrap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

all: $(NAME)

$(NAME): $(SRCS)
	@echo "$(BLUE)Compiling $(NAME).$(RESET)"
	c++ $(FLAGS) $(SRCS) -o $(NAME)

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

