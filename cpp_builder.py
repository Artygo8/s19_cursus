# https://pyformat.info/


import sys
import datetime


OWNER = "agossuin"
SCHOOL = "s19.be"


now = datetime.datetime.now()
date = now.strftime("%Y/%m/%d %H:%M:%S")


INCLUDES = """\
# include <iostream>
# include <string>

using std::string;
using std::cout;

"""


CMAIN = """
int main(int argc, char const *argv[])
{

	return 0;
}"""


def header(name):
    return f"""/* ************************************************************************** */
/*{" ":76}*/
/*{" ":56}:::      ::::::::   */
/*   {name:50} :+:      :+:    :+:   */
/*{" ":52}+:+ +:+         +:+     */
/*   By: {OWNER} <{OWNER}@student.{SCHOOL}>{" " * (25 - (2 * len(OWNER)))}+{"#"}+  +:+       +{"#"}+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: {date} by {OWNER}          #+#    #+#             */
/*   Updated: {date} by {OWNER}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

"""


def hpp_class(name):
    return f"""\
class {name}
{'{'}

	private:
		std::string		name;

	public:
		{name} ();
		~{name} ();

		std::string		getName();
		void			setName(std::string name);

{'};'}

# endif
"""


def generate_hpp(name):
    fhpp = open(f"{name}.hpp", "x")  # security
    fhpp = open(f"{name}.hpp", "w")
    fhpp.write(header(f"{name}.hpp"))
    fhpp.write(f"#ifndef {name.upper()}_HPP\n")
    fhpp.write(f"# define {name.upper()}_HPP\n")
    fhpp.write(INCLUDES)
    fhpp.write(hpp_class(name))
    fhpp.close()


def cpp_template(name):
    return f"""#include \"{name}.hpp\"

{name}::{name}()
{'{'}
	std::cout << "-{str(name)} was created" << '\\n';
{'}'}

{name}::~{name}()
{'{'}
	std::cout << "-{str(name)} is being deleted" << '\\n';
{'}'}

void		{name}::setName(std::string name) //generic function
{'{'}
{'}'}

std::string	{name}::getName() //generic function
{'{'}
	return name;
{'}'}
"""


FIRST_PART_MAKEFILE = """
# ================================ VARIABLES ================================= #

NAME	= exec
CXX	= clang++
CFLAGS	= -Wall -Werror -Wextra

SRCDIR	= ./
INCDIR	= include/
OBJDIR	= objs/

CXXFLAGS	+= -I $(INCDIR)

SRCS	= """

LAST_PART_MAKEFILE = """		main.cpp

SRC		:= $(notdir $(SRCS)) # 					Files only
OBJ		:= $(SRC:.cpp=.o)	#					Files only
OBJS	:= $(addprefix $(OBJDIR), $(OBJ)) #		Full path
CSRCS	:= $(addprefix ../, $(SRCS)) #			Compiler

GR	= \\033[32;1m #	Green
RE	= \\033[31;1m #	Red
YE	= \\033[33;1m #	Yellow
CY	= \\033[36;1m #	Cyan
RC	= \\033[0m #	Reset Colors

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

#	runnng

run : $(NAME)
	@echo "$(CY)>>> Running $(NAME)$(RC)"
	./$(NAME)
#	cleaning
clean :
	@echo "$(RE)--- Removing $(OBJ)$(RC)"
	@rm -fd $(OBJS) $(OBJDIR)

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

.PHONY	= all run clean fclean re debug
"""


def generate_cpp(name):
    fhpp = open(f"{name}.cpp", "x")  # security
    fhpp = open(f"{name}.cpp", "w")
    fhpp.write(header(f"{name}.cpp"))
    fhpp.write(cpp_template(name))
    fhpp.close()


def generate_makefile():
    fmakef = open("Makefile", "w")  # no security for the Makefile
    fmakef.write(FIRST_PART_MAKEFILE)
    fmakef.close()


def main():
    fmain = open("main.cpp", "x")  # security for not erasing files
    generate_makefile()
    fmain = open("main.cpp", "w")
    fmain.write(header("main.cpp"))
    for i in sys.argv[1:]:
        fmain.write(f"#include \"{i}.hpp\"\n")
        generate_cpp(i)
        generate_hpp(i)
    fmain.write(CMAIN)
    fmain.close()


main()
