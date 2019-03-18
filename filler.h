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

char **save_input_piece(t_input *new);
char **save_input_map(t_input *new);
char *valid(char *l, t_input *new, char *chr, int x);
int p_error(char *s);



#endif

// while (get_next_line(0, &l) == 1)
// 	{
// 		xy = ft_strsplit((l + 8), 32);
// 	new.x = ft_atoi(xy[1]);
// 	new.y = ft_atoi(xy[0]);
// 	free(l);
// 	get_next_line(0, &l);
// 	free(l);
// 	// ft_strdel(xy);
// 	new.map = (char**)malloc(sizeof(char*) * new.y + 1);
// 	while (i < new.y)
// 	{
// 		new.i = 3;
// 		get_next_line(0, &l);
// 		if (!(new.map[i] = valid(l, &new, ".oOxX")))
// 			return (p_error("kokoko"));
// 		// printf("new[%d] = %s\n", i, xy[i]);
// 		i++;
// 	}
// 	new.map[i] = NULL;
// 	// 	// save_input_map(&new);
// 		// printf("new[%d] = %s\n", i, new.map[i]);

// 		// fprintf(fd, "---%s\n", l);
// 		// if (!(new.map = save_input_map(&new)))
// 		// 	return(p_error("kekeke"));
// 		// if (!(new.piece = save_input_piece(&new)))
// 		// 	return(p_error("kekeke"));

// 		i = 0;
// 	new.i = -1;
// 	get_next_line(0, &l);
// 	fprintf(fd, "+++%s\n", l);// ft_strdel(xy);
// 	i = 0;
// 	xy = ft_strsplit((l + 6), 32);
// 	new.x = ft_atoi(xy[1]);
// 	new.y = ft_atoi(xy[0]);
// 	new.piece = (char**)malloc(sizeof(char*) * new.y + 1);
// 	while (i < new.y)
// 	{
// 		get_next_line(0, &l);
// 		if (!(new.piece[i] = valid(l, &new, ".*")))
// 			return(NULL);
// 		// printf("piece[%d] = %s\n", i, new->piece[i]);
// 		i++;
// 	}
// 	ft_next_move(&new, &base);
// 		printf("%d %d\n", new.xres, new.yres);
// 		i++;

// 	}
