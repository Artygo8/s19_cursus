
# ================================ VARIABLES ================================= #

NAME	= ex05
CXX	= clang++
CFLAGS	= -Wall -Werror -Wextra

SRCDIR	= ./
INCDIR	= include/
OBJDIR	= objs/

CXXFLAGS	+= -I $(INCDIR)

SRCS	= 	main.cpp Human.cpp Brain.cpp

SRC		:= $(notdir $(SRCS)) # 					Files only
OBJ		:= $(SRC:.cpp=.o)	#					Files only
OBJS	:= $(addprefix $(OBJDIR), $(OBJ)) #		Full path
CSRCS	:= $(addprefix ../, $(SRCS)) #			Compiler

GR	= \033[32;1m #	Green
RE	= \033[31;1m #	Red
YE	= \033[33;1m #	Yellow
CY	= \033[36;1m #	Cyan
RC	= \033[0m #	Reset Colors

# ================================== RULES =================================== #

all : $(NAME)

#	linking
$(NAME)	: $(OBJS)
	@printf "$(YE)&&& Linking $(OBJ) to $(NAME)$(RC)\n"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

#	compiling
$(OBJS) : $(SRCS)
	@printf "$(GR)+++ Compiling $(SRC) to $(OBJ)$(RC)\n"
	@mkdir -p $(OBJDIR)
	@cd $(OBJDIR) && $(CXX) $(CXXFLAGS) -I ../$(INCDIR) -c $(CSRCS)

#	runnng

run : $(NAME)
	@printf "$(CY)>>> Running $(NAME)$(RC)\n"
	./$(NAME)
#	cleaning
clean :
	@printf "$(RE)--- Removing $(OBJ)$(RC)\n"
	@rm -fd $(OBJS) $(OBJDIR)

fclean : clean
	@printf "$(RE)--- Removing $(NAME)$(RC)\n"
	@rm -f $(NAME)

re : fclean all

debug :
	@printf "SRCS $(SRCS)"
	@printf "SRC $(SRC)"
	@printf "OBJS $(OBJS)"
	@printf "OBJ $(OBJ)"
	@printf "CSRCS $(CSRCS)"
	@printf "CFLAGS $(CFLAGS)"

.PHONY	= all run clean fclean re debug
