#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define ABS(Value) (((Value) < 0) ? -(Value) : (Value))

typedef struct s_filler
{
	int	player;
	char *me;
	char *bot;
}				t_filler;

typedef struct s_input
{
	int x;
	int xm;
	int y;
	int ym;
	int i;
	char **map;
	char **piece;
	int xres;
	int yres;
	int min_d;

}				t_input;

int save_input_piece(t_input *new);
int save_input_map(t_input *new);
char *valid(char *l, t_input *new, char *chr, int x);
int p_error(char *s);



#endif
