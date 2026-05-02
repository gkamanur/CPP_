# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/16 16:44:04 by gkamanur          #+#    #+#              #
#    Updated: 2026/03/26 14:29:51 by gkamanur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ex_03
CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -I./includes

# =========================
# SOURCE FILES
# =========================
CORE_SRCS	= core/Amateria.cpp core/Character.cpp core/MateriaSource.cpp
SPELL_SRCS	= spells/Ice.cpp spells/Cure.cpp
NEW_SPELL 	= spells/Fire.cpp
MAIN_SRCS	= main.cpp
MAIN_SRCS_N	= main_fire.cpp

SRCS = $(CORE_SRCS) $(SPELL_SRCS)
SRCS_NEW = $(NEW_SPELL)
# =========================
# OBJECT DIRECTORY
# =========================
OBJDIR = obj

# Convert src → obj path
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)
OBJM = $(MAIN_SRCS:%.cpp=$(OBJDIR)/%.o)
OBJM_N = $(MAIN_SRCS_N:%.cpp=$(OBJDIR)/%.o)
OBJS_NEW = $(SRCS_NEW:%.cpp=$(OBJDIR)/%.o)
# =========================
# BUILD
# =========================
all: $(NAME)

$(NAME): $(OBJS) $(OBJM)
	$(CXX) $(CXXFLAGS)  $(OBJS) $(OBJM) -o $(NAME)

# =========================
# COMPILE RULE
# =========================
$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
spell:
	@echo "Compiling new spell..."
	@$(MAKE) $(NEW_SPELL:%.cpp=$(OBJDIR)/%.o)
	@echo "✓ Spell compiled"
	
main: $(MAIN_SRCS_N:%.cpp=$(OBJDIR)/%.o)
	@echo "$(GREEN)✓ Main compiled$(NC)"
	@$(MAKE) relink

relink: $(OBJS) $(OBJM_N)
	@echo "$(YELLOW)🔄 Forcing relink...$(NC)"
	$(CXX) $(CXXFLAGS) $(OBJS) $(OBJS_NEW) $(OBJM_N) -o $(NAME)
	@echo "$(GREEN)  ✓ Relinked successfully$(NC)"
# =========================
# CLEAN
# =========================
clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: all
	@echo "$(YELLOW)🔍 Running valgrind...$(NC)"
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re