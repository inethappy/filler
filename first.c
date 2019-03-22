#include "filler.h"
#include <fcntl.h>
#include <stdio.h>
// ./filler_vm -p1 ./mkotytsk.filler -p2 players/abanlin.filler -v -f maps/map00
// FILE *fd;
// fd = fopen("tr.txt", "a");

// fprintf(fd, "4jgk8ruofn\n");



void put_piece(t_input *new, t_filler *base)
{
	int jp;
	int ip;

	jp = 0;
	ip = 0;
	while (base->piece[jp] != NULL)
	{
		while (base->piece[jp][ip])
		{
			if (base->piece[jp][ip] == '*')
				if (check(base, new, jp, ip))
					search_path(base, new, jp, ip);
			ip++;
		}
		ip = 0;
		jp++;
	}
}

void ft_next_move(t_input *new, t_filler *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (base->map[j] != NULL)
	{
		while (base->map[j][i])
		{
			if (ft_strchr(base->me, base->map[j][i]))
			{
				new->jm = j;
				new->im = i;
				put_piece(new, base);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

int game(t_input *new, t_filler *base)
{
	int		i;
    char	*l;

	l = NULL;
	i = 0;
	new->min_d = -1;
	if (!save_input_map(new, base))
		return(0);
	if (!save_input_piece(new, base))
		return(0);
	ft_next_move(new, base);
	ft_printf("%d %d\n", new->yres, new->xres);
	new->yres = 0;
	new->xres = 0;
	get_next_line(0, &l);
	free(l);
	return (1);
}

void save_input(t_input *new, t_filler *base)
{
    int		i;
	char	**xy;

	i = -1;
	base->map = (char**)malloc(sizeof(char*) * new->ym + 1);
	while (++i < new->ym)
		base->map[i] = (char*)malloc(sizeof(char*) * new->xm + 1);
	base->map[i] = NULL;
	i = -1;
	base->piece = (char**)malloc(sizeof(char*) * new->ym + 1);
	while (++i < new->ym)
		base->piece[i] = (char*)malloc(sizeof(char*) * new->xm + 1);
	base->piece[i] = NULL;
}

int main(void)
{
    char		*l;
	t_filler	base;
	t_input		new;

	ft_bzero(&new, sizeof(new));
	ft_bzero(&base, sizeof(t_filler));
	if (get_next_line(0, &l) > 0)
	{
		if (!l[10] || (l[10] != '1' && l[10] != '2') || (l[11] != ' '))
			return(p_error("kokoko"));
		new.player = l[10] - 48;
		base.me = (new.player == 1) ? "oO" : "xX";
		base.bot = (new.player == 1) ? "xX" : "oO";
		ft_strdel(&l);
		get_next_line(0, &l);
		new.ym = ft_atoi(l + 8);
		new.xm = ft_atoi(l + (ft_strrchr(l, ' ') - l));
		ft_strdel(&l);
		save_input(&new, &base);
		while (game(&new, &base))
			;
	}
	// system("leaks mkotytsk.filler > test");
    return 0;
}


