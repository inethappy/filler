#include "filler.h"
#include <fcntl.h>
#include <stdio.h>
// ./filler_vm -p1 ./mkotytsk.filler -p2 players/abanlin.filler -v -f maps/map00
// FILE *fd;
// fd = fopen("tr.txt", "a");

// fprintf(fd, "4jgk8ruofn\n");
void search_path(t_filler *base, t_input *new, int cj, int ci, int cjp, int cip)
{
	int j = 0;
	int i = 0;
	int d = 0;
	int buf = 0;

	while (new->map[j] != NULL)
	{
		while (new->map[j][i])
		{
			if (ft_strchr(base->bot, new->map[j][i]))
			{
				d = ABS(j - cj) + ABS(i - ci);
				new->min_d = (new->min_d == -1) ? (d + 1) : new->min_d;
				if (new->min_d > d)
				{
					new->min_d = d;
					new->xres = ABS(ci - cip);
					new->yres = ABS(cj - cjp);
				}
			}
			i++;
		}
		i = 0;
		j++;
	}
}

int check(t_filler *base, t_input *new, int jp, int ip, int j, int i)
{
	int bi;

	bi = -1;
	int h = j;
	int u = i;
	new->map[j][i] = 'a';
	i = i - ip;
	j = j - jp;
	if (i < 0 || j < 0)
	{
		new->map[h][u] = (base->player == 1) ? 'O' : 'X';
		return (0);
	}
	ip = -1;
	jp = -1;
	bi = i;
	while (new->map[j] && (++jp < new->y))
	{
		while (new->map[j][i] && (++ip < new->x))
		{
			if (((ft_strchr(base->me, new->map[j][i]) || ft_strchr(base->bot, new->map[j][i])) && new->piece[jp][ip] != '.'))
			{
				new->map[h][u] = (base->player == 1) ? 'O' : 'X';
				return (0);
			}
			i++;
		}
		if (!new->map[j][i])
			break ;
		j++;
		i = bi;
		ip = -1;
	}
	if (ip < (new->x) && ip > -1)
	{
		while (new->piece[jp][ip])
		{
			if (new->piece[jp][ip] == 42)
			{
				new->map[h][u] = (base->player == 1) ? 'O' : 'X';
				return (0);
			}
			ip++;
			break ;
		}
		jp++;
	}
	if (jp < (new->y))
	{
		while (jp < new->y)
		{
			if (ft_strchr(new->piece[jp], 42))
			{
				new->map[h][u] = (base->player == 1) ? 'O' : 'X';
				return (0);
			}
			jp++;
		}
	}
	new->map[h][u] = (base->player == 1) ? 'O' : 'X';
	return (1);
}

void put_piece(t_input *new, t_filler *base, int j, int i)
{
	int jp;
	int ip;
	jp = 0;
	ip = 0;
	while (new->piece[jp] != NULL)
	{
		while (new->piece[jp][ip])
		{
			if (new->piece[jp][ip] == '*')
				if (check(base, new, jp, ip, j, i))
					search_path(base, new, j, i, jp, ip);
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
	while (new->map[j] != NULL)
	{
		while (new->map[j][i])
		{
			if (ft_strchr(base->me, new->map[j][i]))
				put_piece(new, base, j, i);
			i++;
		}
		i = 0;
		j++;
	}
}

int game(t_input *new, t_filler *base)
{
	int i;
    char *l;
	l = NULL;

	i = 0;
	new->min_d = -1;

	if (!save_input_map(new))
		return(0);
	if (!save_input_piece(new))
		return(0);
	ft_next_move(new, base);
	ft_printf("%d %d\n", new->yres, new->xres);
	new->yres = 0;
	new->xres = 0;
	get_next_line(0, &l);
	free(l);
	return (1);
}

int main(void)
{
    char *l;
	int res;
    int i = 0;

	t_filler base;
	char **xy;
	t_input new;

	ft_bzero(&new, sizeof(new));
	ft_bzero(&base, sizeof(t_filler));
	if ((res = get_next_line(0, &l)) > 0)
	{
		if (!l[10] || (l[10] != '1' && l[10] != '2') || (l[11] != ' '))
			return(p_error("kokoko"));
		base.player = l[10] - 48;
		base.me = (base.player == 1) ? "oO" : "xX";
		base.bot = (base.player == 1) ? "xX" : "oO";
		ft_strdel(&l);
		get_next_line(0, &l);
		i = -1;
		new.ym = ft_atoi(l + 8);
		new.xm = ft_atoi(l + (ft_strrchr(l, ' ') - l));
		ft_strdel(&l);
		new.map = (char**)malloc(sizeof(char*) * new.ym + 1);
		while (++i < new.ym)
			new.map[i] = (char*)malloc(sizeof(char*) * new.xm + 1);
		new.map[i] = NULL;
		i = -1;
		new.piece = (char**)malloc(sizeof(char*) * new.ym + 1);
		while (++i < new.ym)
			new.piece[i] = (char*)malloc(sizeof(char*) * new.xm + 1);
		new.piece[i] = NULL;
		while (game(&new, &base))
			;
	}
	system("leaks mkotytsk.filler > test");
    return 0;
}


