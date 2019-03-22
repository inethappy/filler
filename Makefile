NAME	=	mkotytsk.filler
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SOURCES	=	first.c validation.c check.c
OBJECTS	=	$(SOURCES:.c=.o)
LIBFT	=	libft/libft.a
PRINTF	=	ft_printf/libftprintf.a

all:	$(NAME)

$(NAME):
	#  @make -C $(LIBFT)
	#  @make -C $(PRINTF)
	 $(CC) $(SOURCES) $(LIBFT) $(PRINTF) -o $(NAME)
	 # -L $(LIBFT) libft/*.c -I libft/libft.h -I ft_printf/ft_printf.h -o $(NAME) #$(CFLAGS)
%.o: ./%.c
	gcc -o $@ -c $<
clean:
	rm -rf *.o
	rm -rf libft/*.o
fclean: clean
	rm -rf $(NAME)
re: fclean all
