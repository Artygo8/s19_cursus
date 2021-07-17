
# ================================ VARIABLES ================================= #

NAME	= exec
CXX	= clang++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCDIR	= ./
INCDIR	= include/
OBJDIR	= objs/

CXXFLAGS	+= -I $(INCDIR)

SRCS	= 		main_vector.cpp

SRC		:= $(notdir $(SRCS)) # 					Files only
OBJ		:= $(SRC:.cpp=.o)	#					Files only
OBJS	:= $(addprefix $(OBJDIR), $(OBJ)) #		Full path
CSRCS	:= $(addprefix ../, $(SRCS)) #			Compiler

GR	= \033[32;1m #	Green
RE	= \033[31;1m #	Red
YE	= \033[33;1m #	Yellow
CY	= \033[36;1m #	Cyan
SCY	= \033[36m #	SmallCyan
RC	= \033[0m #	Reset Colors

# ================================== RULES =================================== #

all : $(NAME)

#	linking
$(NAME)	: $(OBJS)
	@printf "$(YE)&&& Linking $(OBJ) to $(NAME)$(RC)"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

#	compiling
$(OBJS) : $(SRCS)
	@printf "$(GR)+++ Compiling $(SRC) to $(OBJ)$(RC)"
	@mkdir -p $(OBJDIR)
	@cd $(OBJDIR) && $(CXX) $(CXXFLAGS) -I ../$(INCDIR) -c $(CSRCS)

#	running

run : $(NAME)
	@printf "$(CY)>>> Running $(NAME)$(RC)"
	./$(NAME)

test :$(NAME)
	@printf "$(SCY)
	# put your custom tests here
	@printf "$(RC)

#	cleaning
clean :
	@printf "$(RE)--- Removing $(OBJ)$(RC)"
	@rm -fd $(OBJS) $(OBJDIR)

fclean : clean
	@printf "$(RE)--- Removing $(NAME)$(RC)"
	@rm -f $(NAME)

re : fclean all

debug :
	@printf "SRCS $(SRCS)"
	@printf "SRC $(SRC)"
	@printf "OBJS $(OBJS)"
	@printf "OBJ $(OBJ)"
	@printf "CSRCS $(CSRCS)"
	@printf "CFLAGS $(CFLAGS)"

.PHONY	= all run clean fclean re debug test
