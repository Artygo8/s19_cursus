S_SRC	=	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
SRC		=	$(addprefix srcs/, $(S_SRC))
OBJ		=	$(SRC:.s=.o)

S_BONUS	=	ft_atoi_base.s
SRC_BONUS	=	$(addprefix bonus/, $(BONUS_FILES))
OBJ_BONUS	=	$(SRC_BONUS:.s=.o)

NAME	=	libasm.a
EXE		=	testing/test

ASM		=	nasm
ASFLAGS	=	-f macho64
CC		=	gcc
RM		=	rm -f
AR		=	ar -rc

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)

bonus:		$(OBJ) $(OBJ_BONUS)
			@$(AR) $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(EXE)

re:			fclean all

main:		re bonus
			@$(CC) -o $(EXE) libasm.a testing/*.c backups/ft_atoi_base.c \
			&& ./$(EXE)

%.o: 		%.s
			@$(ASM) $(ASFLAGS) $< -o $@
