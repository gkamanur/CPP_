# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/16 16:44:04 by gkamanur          #+#    #+#              #
#    Updated: 2026/03/23 15:15:04 by gkamanur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex_01
CC		    = c++
CFLAGS	    = -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJDIR		= obj
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re