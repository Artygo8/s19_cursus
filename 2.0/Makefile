# ================================ VARIABLES ================================= #

NAME	= exec

SRCDIR	= ./
INCDIR	= include/
OBJDIR	= objs/

SRCS	= main_vector.cpp

SRC		:= $(notdir $(SRCS))# Files only
OBJ		:= $(SRC:.cpp=.o)# Files only
OBJS	:= $(addprefix $(OBJDIR),$(OBJ))# Full path
CSRCS	:= $(addprefix ../, $(SRCS))# Compiler

CXX		= clang++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98
CXXFLAGS+= -I $(INCDIR)

GR	= \033[32;1m # Green
RE	= \033[31;1m # Red
YE	= \033[33;1m # Yellow
CY	= \033[36;1m # Cyan
SCY	= \033[36m   # SmallCyan
RC	= \033[0m    # Reset Colors

# ================================== RULES =================================== #

$(NAME)	: $(OBJS)
	@printf "$(YE)&&& Linking $(OBJ) to $(NAME)$(RC)\n"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

all : $(NAME)

run : $(NAME)
	@printf "$(CY)>>> Running $(NAME)$(RC)\n"
	./$(NAME)

clean :
	@printf "$(RE)--- Removing $(OBJ)$(RC)\n"
	@rm -fd $(OBJS) $(OBJDIR)

fclean : clean
	@printf "$(RE)--- Removing $(NAME)$(RC)\n"
	@rm -f $(NAME)

re : fclean all

$(OBJS) : $(SRCS)
	@printf "$(GR)+++ Compiling $(SRC) to $(OBJ)$(RC)\n"
	@mkdir -p $(OBJDIR)
	@cd $(OBJDIR) && $(CXX) $(CXXFLAGS) -I ../$(INCDIR) -c $(CSRCS)

.PHONY	= all run clean fclean re test
