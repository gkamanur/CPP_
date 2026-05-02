# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/11 14:52:46 by gkamanur          #+#    #+#              #
#    Updated: 2026/03/25 11:08:29 by gkamanur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXERCISES = $(sort $(wildcard ex*))
OBJDIR    = obj

all: $(EXERCISES)

$(EXERCISES):
	@echo "Building $@..."
	@if [ -f $@/Makefile ]; then \
		name=$$(grep -m1 '^NAME' $@/Makefile | sed 's/.*=[[:space:]]*//'); \
		$(MAKE) --no-print-directory -C $@ OBJDIR=../$(OBJDIR)/$@ NAME=../$$name; \
	fi

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@for dir in $(EXERCISES); do \
		if [ -f $$dir/Makefile ]; then \
			name=$$(grep -m1 '^NAME' $$dir/Makefile | sed 's/.*=[[:space:]]*//'); \
			rm -f ./$$name; \
		fi; \
	done

lclean: clean
	@echo "local clean (executables)..."
	@for dir in $(EXERCISES); do \
		if [ -f $$dir/Makefile ]; then \
			$(MAKE) --no-print-directory -C $$dir fclean; \
		fi; \
	done

re: fclean all

.PHONY: all clean fclean re $(EXERCISES)