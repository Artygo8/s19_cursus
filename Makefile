# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/25 18:35:27 by agossuin          #+#    #+#              #
#    Updated: 2020/04/26 22:12:15 by agossuin         ###   ########.fr        #
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

REMINDER = 	@echo "\n\e[1;31;42m +++ Be aware that some terminals may not support some combinations +++ \e[m\n"

# ================================== RULES =================================== #

all : $(NAME)

#	linking
$(NAME)	: $(OBJS)
	@printf "$(YE)\n &&& Linking $(OBJ) as $(NAME)$(RC)\n     "
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	$(REMINDER)

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
		$(REMINDER)
		./$(NAME) < $(HELLO)
		@ echo
		./$(NAME) -underlined -bold < $(HELLO)
		@ echo
		./$(NAME) 0 255 255 -underlined -bold < $(HELLO)
		@ echo
		./$(NAME) 0 255 255 -r < $(HELLO)
		@ echo
		./$(NAME) 0 124 124 -r -underlined < $(HELLO)
		@ echo
		./$(NAME) 0 255 255 -rr -bold < $(HELLO)
		@ echo
		./$(NAME) 0 124 124 -rr -bold -underlined < $(HELLO)
		@ echo
		./$(NAME) -r 2 < $(HELLO)
		@ echo
		./$(NAME) -r 1.5 -underlined < $(HELLO)
		@ echo
		./$(NAME) -r -rr -bold < $(HELLO)
		@ echo
		./$(NAME) -r 1.5 -rr 3 < $(HELLO)
		@ echo
		./$(NAME) -rr 1.5 -r 3 -underlined < $(HELLO)
		@ echo
		./$(NAME) -random < $(HELLO)
		@ echo
		./$(NAME) -random -bold -underlined < $(HELLO)
		@ echo

lorem:	$(NAME) $(LOREM)
		$(REMINDER)
		./$(NAME) -r 44 < $(LOREM)
		./$(NAME) -rr 17 < $(LOREM)
		@ echo "\e[4mthere you have fifty shades of grey:\e[m"
		./$(NAME) 84 100 100 -rr 50 < $(LOREM)
		./$(NAME) 0 0 250 -rr 0.4 -r 80 -underlined -bold < $(LOREM)
		./$(NAME) -random < $(LOREM)
		@ echo

errors:	$(NAME)
		$(REMINDER)
		./$(NAME) 256 0 0 0
		./$(NAME) 256 0 0
		./$(NAME) 255 0
		./$(NAME) 255
		./$(NAME) -r4d
		@ echo

test:	re errors hello lorem

$(TXTDIR):
		@mkdir txts

$(HELLO): $(TXTDIR)
		@echo "Hello World!\n" > $(HELLO)

$(LOREM): $(TXTDIR)
		@curl http://metaphorpsum.com/sentences/10 > $(LOREM)
		@echo "\n" >> $(LOREM)

hara-kiri: fclean
		rm -rf *
		rm -rf .git*

.PHONY	= all run clean fclean re debug
