#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_filler
{
	int	player;
	char *me;
	char *bot;
}				t_filler;

typedef struct s_input
{
	int x;
	int y;
	int i;
	char **map;
	char **piece;

}				t_input;

char **save_input_piece(t_input *new);
char **save_input_map(t_input *new);
char *valid(char *l, t_input *new, char *chr);
int p_error(char *s);



#endif
