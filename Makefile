NAME	=	mkotytsk.filler
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SOURCES	=	first.c
OBJECTS	=	$(SOURCES:.c=.o)
LIB		=	libft/

all:	$(NAME)

$(NAME):
	 @make -C $(LIB)
	 $(CC) $(SOURCES) -L $(LIB) libft/*.c -I libft/libft.h -o $(NAME) #$(CFLAGS)
%.o: ./%.c
	gcc -o $@ -c $<
test:
	$(CC) -g -L. libft.a $(SOURCES) main.c -o $(OUTPUT)
clean:
	rm -rf *.o
	rm -rf libft/*.o
fclean: clean
	rm -rf $(NAME)
re: fclean all
