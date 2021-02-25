# ================================ VARIABLES ================================= #

NAME	= test_containers

SRCS	= main.cpp \
			tests/test_list.cpp \
			tests/test_queue.cpp \
			tests/test_stack.cpp \
			tests/test_vector.cpp

OBJS	= $(SRCS:.cpp=.o)

CXX		= clang++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98 -g3 -I tests -I ft_containers
# CXXFLAGS+= -I $(INCDIR)

GR	= \033[32;1m # Green
RE	= \033[31;1m # Red
YE	= \033[33;1m # Yellow
CY	= \033[36;1m # Cyan
SCY	= \033[36m   # SmallCyan
RC	= \033[0m    # Reset Colors

# ================================== RULES =================================== #

$(NAME)	: $(OBJS)
	@printf "$(YE)&&& Linking $(OBJS) to $(NAME)$(RC)\n"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

all : $(NAME)

run : $(NAME)
	@printf "$(CY)>>> Running $(NAME)$(RC)\n"
	./$(NAME)

clean :
	@printf "$(RE)--- Removing $(OBJ)$(RC)\n"
	rm -rf $(OBJS) $(OBJDIR)

fclean : clean
	@printf "$(RE)--- Removing $(NAME)$(RC)\n"
	rm -rf $(NAME)

re : fclean all


.PHONY	= all run clean fclean re test
