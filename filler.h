#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_filler
{
	int	player;

}				t_filler;

typedef struct s_map
{
	int x;
	int y;
	int i;
	char **new;
	char **piece;
}				t_map;


#endif
