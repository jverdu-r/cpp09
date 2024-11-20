# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 15:11:39 by jverdu-r          #+#    #+#              #
#    Updated: 2024/11/20 15:12:26 by jverdu-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc
SRC = src/main.cpp \
	src/Date.cpp \
	src/BitcoinExchange.cpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
LDFLAGS = -std=c++98
RM = /bin/rm -rf
OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	c++ $(LDFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re