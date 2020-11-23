# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/27 12:17:04 by agossuin          #+#    #+#              #
#    Updated: 2020/04/27 12:17:05 by agossuin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

SRCS	= megaphone.cpp

NAME	= megaphone

CC		= clang++
CFLAGS	= -Wall -Werror -Wextra

SRCDIR	= ./
OBJDIR	= objs/

OBJ		:= $(SRCS:.cpp=.o)	#				Files only
OBJS	:= $(addprefix $(OBJDIR), $(OBJ)) #		Full path
SRCS	:= $(addprefix $(SRCDIR), $(SRCS)) #			Full path
CSRCS	:= $(addprefix ../, $(SRCS)) #			Compiler

GR	= \033[32;1m #	Green
RE	= \033[31;1m #	Red
YE	= \033[33;1m #	Yellow
CY	= \033[36;1m #	Cyan
SCY	= \033[36m #	Small Cyan
RC	= \033[0m #	Reset Colors

# ================================== RULES =================================== #

all : $(NAME)

$(NAME)	: $(OBJS)
	@printf "$(YE)&&& Linking $(OBJ) to $(NAME)$(RC)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	@printf "$(GR)+++ Compiling $(SRC) to $(OBJ)$(RC)"
	mkdir -p $(OBJDIR)
	cd $(OBJDIR) && $(CC) $(CFLAGS) -I ../$(INCDIR) -c $(CSRCS)

run : $(NAME)
	@printf "$(CY)>>> Running $(NAME)$(RC)"
	./$(NAME)

clean :
	@printf "$(RE)--- Removing $(OBJS)$(RC)"
	rm -rf $(OBJS) $(OBJDIR)

fclean : clean
	@printf "$(RE)--- Removing $(NAME)$(RC)"
	rm -f $(NAME)

re : fclean all

test : $(NAME)
	@printf "$(SCY)"
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(NAME)
	@printf "$(RC)"

debug :
	@printf "SRCS $(SRCS)"
	@printf "SRC $(SRC)"
	@printf "OBJS $(OBJS)"
	@printf "OBJ $(OBJ)"
	@printf "CSRCS $(CSRCS)"
	@printf "CFLAGS $(CFLAGS)"

.PHONY	= all run clean fclean re debug test
