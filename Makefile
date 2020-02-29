SRC		=	ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s

OBJ		=	$(SRC:.s=.o)

EXE		=	test
NAME	=	libasm.a

ASM		=	nasm
ASFLAGS	=	-f macho64
CC		=	gcc
RM		=	rm -f
AR		=	ar -rc

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(EXE)

re:			fclean all

test:		re
			@$(CC) -o $(EXE) libasm.a main.c && ./$(EXE)

%.o: %.s
			@$(ASM) $(ASFLAGS) $< -o $@
