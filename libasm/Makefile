OS		:=	$(shell uname -s)

ifeq (${OS},Linux)
	ASFLAGS		=	-f elf64
	SRC_FOLDER	=	srcs_linux
else
	ASFLAGS		=	-f macho64
	SRC_FOLDER	=	srcs_macos
endif

S_SRC	=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s \
			ft_strdup.s ft_putstr.s
SRC		=	$(addprefix $(SRC_FOLDER)/, $(S_SRC))
OBJ		=	$(SRC:.s=.o)

C_TEST	=	main.c test_rw.c
TEST	=	$(addprefix $(SRC_FOLDER)/, $(S_SRC))
EXE		=	test

NAME	=	libasm.a

ASM		=	nasm
CC		=	gcc
RM		=	rm -f
AR		=	ar -rcs

all:		$(NAME)

$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)

bonus:		$(OBJ) $(OBJ_BONUS)
			$(AR) $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(EXE)

re:			fclean all

main:		re bonus
			$(CC) -o $(EXE) $(TEST) -L. -llibasm && ./$(EXE)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

%.o: 		%.s
			@$(ASM) $(ASFLAGS) $< -o $@
