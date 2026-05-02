# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/16 16:44:04 by gkamanur          #+#    #+#              #
#    Updated: 2026/04/29 17:55:10 by gkamanur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PmergeMe
CC		    = c++
CFLAGS	    = -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp PmergeMe.cpp
OBJDIR		= obj
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

# Variables for HTML visualizer
HTML_FILE = visualizer.html
BROWSER = xdg-open

# Default target
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

# Open the HTML visualizer in default browser (Linux only)
.PHONY: open
open:
	@if [ -f $(HTML_FILE) ]; then \
		echo "🚀 Opening $(HTML_FILE) in default browser..."; \
		$(BROWSER) $(HTML_FILE); \
	else \
		echo "❌ Error: $(HTML_FILE) not found!"; \
		echo "💡 Please make sure $(HTML_FILE) exists in the current directory."; \
		exit 1; \
	fi

# Help menu
.PHONY: help
help:
	@echo "📖 Available commands:"
	@echo "  make          - Build PmergeMe executable"
	@echo "  make open     - Open sorting-visualizer.html in browser"
	@echo "  make clean    - Remove object files"
	@echo "  make fclean   - Remove object files and executable"
	@echo "  make re       - Rebuild everything"
	@echo "  make help     - Show this help message"

.PHONY: all clean fclean re open help