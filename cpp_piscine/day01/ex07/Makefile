
# ================================ VARIABLES ================================= #

NAME	= replace
CXX		= clang++
CFLAGS	= -Wall -Werror -Wextra

SRCDIR	= ./
INCDIR	= include/
OBJDIR	= objs/

CXXFLAGS	+= -I $(INCDIR)

SRCS	= 		main.cpp

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

all : $(NAME) test.txt

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
run : $(NAME) test.txt
	@printf "$(CY)>>> Running $(NAME)$(RC)\n"
	./$(NAME) test.txt jammin codin

#	cleaning
clean :
	@printf "$(RE)--- Removing $(OBJ)$(RC)\n"
	@rm -fd $(OBJS) $(OBJDIR)

fclean : clean
	@printf "$(RE)--- Removing $(NAME)$(RC)\n"
	@rm -f $(NAME)
	@rm -f test.txt
	@rm -f test.txt.replace

re : fclean all

debug :
	@printf "SRCS $(SRCS)\n"
	@printf "SRC $(SRC)\n"
	@printf "OBJS $(OBJS)\n"
	@printf "OBJ $(OBJ)\n"
	@printf "CSRCS $(CSRCS)\n"
	@printf "CFLAGS $(CFLAGS)\n"

test.txt:
	@echo -en "Ooh, yeah\nWell, alright\nWe're jammin'\nSing it, I want to jam it with you\nWe're jammin', we're jammin'\nAnd I hope you like jammin' too\nAin't no rules, ain't no vow\nYou can do it anyhow\n'Cause I and I will see you through\nBut every day we pay the price\nCome a little sacrifice\njammin' 'til the jam is through\nOoh yeah, we're jammin', hey\nTo think that jammin' was a thing of the past\nWe're jammin', we're jammin'\nAnd I hope this jam is gonna last\nNo bullet can stop us now, we neither beg nor we won't bow\nNeither can be bought nor sold\nWe all defend the right, Jah-Jah children must unite\n'Cause life is worth much more than gold\nOoh yeah, we're jammin'\nAnd we're jammin' in the name of the Lord\nWe're jammin', we're jammin'\nAnd we're jammin' right straight from yard\nAy\nHoly Mount Zion\nHoly Mount Zion\nJah sitteth in Mount Zion\nAnd ruleth all creation, hey, we're rammin'\nI want to tell you that we're here and we're jammin'\nI really mean it, I wanna, I wanna, I wanna jam it (I wanna jam it with you)\njammin', jammin'\nAnd I hope you like jammin' too\nWell, I hope you like jammin', I hope you like jammin'\nI wanna, I wanna, I wanna jam with you\njammin', jammin'\nHope you like jammin' too\nWell, well, well (jammin', jammin', jammin', jammin')\n(I wanna jam it with you)\n(jammin', jammin', jammin', jammin')\n(Hope you like jammin' too)\nHoly-holy\nHoly-holy-holy (Zion) oh\njammin'\njammin'\nI wanna jam it with you\nMister Tyrone Downie!\nFamily Man Barret!\nMister Al Anderson!\nMister Carleton!\nAl Seeco!\nEarl Wire!\nHave fun!" \
	> test.txt

.PHONY	= all run clean fclean re debug
