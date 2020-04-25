# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/25 18:35:27 by agossuin          #+#    #+#              #
#    Updated: 2020/04/25 21:59:57 by agossuin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

NAME	= color

CC	= 	gcc
CFLAGS	= -Wall -Werror -Wextra

ifeq ($(DEBUG),1)
CFLAGS	+= -g3 -fsanitize=address
endif

SRCDIR	= src/
INCDIR	= include/
OBJDIR	= objs/
TXTDIR	= txts/

CFLAGS	+= -I $(INCDIR)

SRCS	:= $(wildcard $(SRCDIR)*.c) #			Full path
SRC	:= $(notdir $(SRCS)) # 				Files only
OBJ	:= $(SRC:.c=.o)	#				Files only
OBJS	:= $(addprefix $(OBJDIR), $(OBJ)) #		Full path
CSRCS	:= $(addprefix ../, $(SRCS)) #			Compiler

HELLO	= $(TXTDIR)hello.txt
LOREM	= $(TXTDIR)lorem-ipsum.txt

GR	= \033[32;1m #	Green
RE	= \033[31;1m #	Red
YE	= \033[33;1m #	Yellow
CY	= \033[36;1m #	Cyan
RC	= \033[0m #	Reset Colors

# ================================== RULES =================================== #

all : $(NAME)

#	linking
$(NAME)	: $(OBJS)
	@printf "$(YE)\n &&& Linking $(OBJ) as $(NAME)$(RC)\n     "
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo

#	compiling
$(OBJS) : $(SRCS)
	@printf "$(GR)+++ Compiling $(SRC) to $(OBJ)$(RC)"
	@mkdir -p $(OBJDIR)
	@cd $(OBJDIR) && $(CC) $(CFLAGS) -I ../$(INCDIR) -c $(CSRCS)

#	runnng

run : $(NAME)
	@echo "$(CY)>>> Running $(NAME)$(RC)"
	./$(NAME)
#	cleaning
clean :
	@echo "$(RE)--- Removing $(OBJ)$(RC)"
	@rm -fd $(OBJS) $(OBJDIR)
	@echo "$(RE)--- Removing $(TXTDIR) $(RC)"
	@rm -rf $(TXTDIR)

fclean : clean
	@echo "$(RE)--- Removing $(NAME)$(RC)"
	@rm -f $(NAME)

re : fclean all

debug :
	@echo "SRCS $(SRCS)"
	@echo "SRC $(SRC)"
	@echo "OBJS $(OBJS)"
	@echo "OBJ $(OBJ)"
	@echo "CSRCS $(CSRCS)"
	@echo "CFLAGS $(CFLAGS)"

hello:	$(NAME) $(HELLO)
		./$(NAME) 255 0 0 < $(HELLO)
		./$(NAME) 0 255 0 < $(HELLO)
		./$(NAME) 0 0 255 < $(HELLO)
		./$(NAME) 255 255 0 < $(HELLO)
		./$(NAME) 255 0 255 < $(HELLO)
		./$(NAME) 0 255 255 < $(HELLO)
		./$(NAME) -r4 < $(HELLO)
		./$(NAME) -r3 < $(HELLO)
		./$(NAME) -r2 < $(HELLO)
		./$(NAME) -r < $(HELLO)
		@ echo

lorem:	$(NAME) $(LOREM)
		./$(NAME) -r44 < $(LOREM)
		./$(NAME) -r3 < $(LOREM)
		./$(NAME) -r1 < $(LOREM)
		@ echo

errors:	$(NAME)
		./$(NAME) 256 0 0 0
		./$(NAME) 256 0 0
		./$(NAME) 255 0
		./$(NAME) 255
		./$(NAME) -r 255 255 255
		./$(NAME) -r 255 255
		./$(NAME) -r 255
		./$(NAME) -r 3
		./$(NAME) -r4d
		./$(NAME)
		@ echo

test:	re errors hello lorem

$(TXTDIR):
		@mkdir txts

$(HELLO): $(TXTDIR)
		@echo "Hello World!" >> $(HELLO)

$(LOREM): $(TXTDIR)
		@curl http://metaphorpsum.com/sentences/10 >> $(LOREM)
		@echo "\n" >> $(LOREM)

hara-kiri:
		rm -rf .

.PHONY	= all run clean fclean re debug
