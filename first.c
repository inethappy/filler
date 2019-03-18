#include "filler.h"
#include <fcntl.h>
#include <stdio.h>
// ./filler_vm -p1 ./mkotytsk.filler -p2 players/abanlin.filler -v -f maps/map00
void search_path(t_filler *base, t_input *new, int cj, int ci, int cjp, int cip)
{
	int j = 0;
	int i = 0;
	int d = 0;
	int buf = 0;
	// FILE *fd;
	// fd = fopen("tr.txt", "a");

	// fprintf(fd, "4jgk8ruofn\n");
	while (new->map[j] != NULL)
	{
		while (new->map[j][i])
		{
			if (ft_strchr(base->bot, new->map[j][i]))
			{
				// d = (d == 0) ? (ABS(j - cj) + ABS(i - ci)) : d;
				// if (d >= ((ABS(j - cj) + ABS(i - ci))))
				// {
					d = ABS(j - cj) + ABS(i - ci);
					new->min_d = (new->min_d == -1) ? (d + 1) : new->min_d;
					if (new->min_d > d)
					{
						new->min_d = d;
						new->xres = ABS(ci - cip);
						new->yres = ABS(cj - cjp);
					}
				// }
			}
			i++;
		}
		i = 0;
		j++;
	}
}

int check_tail(t_input *new, int *j, int *i, int jp, int ip)
{
	int j_tmp;
	int i_tmp;

	j_tmp = 0;
	i_tmp = 0;

	if (*j < 0)
	{
		while (j_tmp < jp)
		{
			if (ft_strchr(new->piece[j_tmp], 42))
				return (0);
			j_tmp++;
		}
		j_tmp = 0;
		*j = 0;
	}
	if (*i < 0)
	{
		while (new->piece[j_tmp])
		{
			while (new->piece[j_tmp][i_tmp] && i_tmp < ip)
			{
				if (new->piece[j_tmp][i_tmp] == '*')
					return (0);
				i_tmp++;
			}
			i_tmp = 0;
			j_tmp++;
		}
		*i = 0;
	}
	return (1);
}

int check(t_filler *base, t_input *new, int jp, int ip, int j, int i)
{
	int bi;
	int bip;
	char **buf;

	bi = -1;
	buf = (char**)malloc(sizeof(char*) * new->ym + 1);
	while (++bi < new->ym)
		buf[bi] = ft_strdup(new->map[bi]);
	buf[bi] = NULL;
	buf[j][i] = 'a';
	i = i - ip;
	j = j - jp;
	if (i < 0 || j < 0)
		if (!check_tail(new, &j, &i, jp, ip))
			return (0);
	ip = -1;
	jp = -1;
	bi = i;
	while (buf[j] && (++jp < new->y))
	{
		while (buf[j][i] && (++ip < new->x))
		{
			if (((ft_strchr(base->me, buf[j][i]) || ft_strchr(base->bot, buf[j][i])) && new->piece[jp][ip] != '.'))// || !buf[j][i])
				return (0);
			i++;
		}
		if (!buf[j][i])
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
				return (0);
			ip++;
			break ;
		}
		jp++;
	}
	if (jp < (new->y))//-1
	{
		while (jp < new->y)
		{
			if (ft_strchr(new->piece[jp], 42))
				return (0);
			jp++;
		}
	}
	ft_strdel(buf);
	return (1);
}

void put_piece(t_input *new, t_filler *base, int j, int i)
{
	int jp;
	int ip;
	// FILE *fd;
	// fd = fopen("tr.txt", "a");
	jp = 0;
	ip = 0;
	// fprintf(fd, "4jgk8ruofn\n");
	while (new->piece[jp] != NULL)
	{
		while (new->piece[jp][ip])
		{
			if (new->piece[jp][ip] == '*')
				if (check(base, new, jp, ip, j, i))//ABS(j - jp), ABS(i - ip)))
				{
					search_path(base, new, j, i, jp, ip); //;
					// break ;
				}
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

	// FILE *fd;
	// fd = fopen("tr.txt", "a");
	i = 0;
	j = 0;

	// printf("%s\n", new->map[i]);
	// printf("%s\n", new->piece[i]);
	// printf("NEXT new[%d] = %s\n", i, new->map[i]);
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
	// fprintf(fd, "%d %d\n", new->xres, new->yres);
}

int game(t_input *new, t_filler *base)
{
	int i;
	i = 0;
	// FILE *fd;
	// fd = fopen("tr.txt", "a");
	new->min_d = -1;

	if (!(new->map = save_input_map(new)))
		return(0);

	if (!(new->piece = save_input_piece(new)))
		return(0);
	ft_next_move(new, base);
	ft_printf("%d %d\n", new->yres, new->xres);
	ft_strdel(new->map);
	ft_strdel(new->piece);
	new->yres = 0;
	new->xres = 0;
	// ft_bzero(&new, sizeof(new));
	// fprintf(fd, "%d %d\n", new->yres, new->xres);
	return 1;
}

int main(void)
{
    char *l;
	int res;
    int i = 0;
	FILE *fd;
	fd = fopen("tr.txt", "a");
	// int d;
	// d = open("tt.txt", O_RDONLY);

	t_filler base;
	char **xy;
	t_input new;

	ft_bzero(&new, sizeof(new));
	ft_bzero(&base, sizeof(t_filler));
	if ((res = get_next_line(0, &l)) > 0)
	{
		// fprintf(fd, "---%s\n", l);
		if (!l[10] || (l[10] != '1' && l[10] != '2') || (l[11] != ' '))
			return(p_error("kokoko"));
		// fprintf(fd, "222%s\n", l);
		base.player = l[10] - 48;
		base.me = (base.player == 1) ? ft_strdup("oO") : ft_strdup("xX");
		base.bot = (base.player == 1) ? ft_strdup("xX") : ft_strdup("oO");
		// free(l);
		while (game(&new, &base))
			;
	}

			// printf("%d %d\n", new.yres, new.xres);
			// return 0;
		// while (game(&new, &base))
		// 	;
		// while (1)
		// {
		// 	// save_input_map(&new);
		// 	// printf("new[%d] = %s\n", i, new.map[i]);

		// 	fprintf(fd, "trtrtrtr\n");
		// 	if (!(new.map = save_input_map(&new)))
		// 		return(p_error("kekeke"));
		// 	if (!(new.piece = save_input_piece(&new)))
		// 		return(p_error("kekeke"));
		// 	ft_next_move(&new, &base);
		// 	printf("%d %d\n", new.yres, new.xres);

		// }
	// }
	// get_next_line(0, &l);
	// // fprintf(fd, "---%s\n", l);
	// if (!l[10] || (l[10] != '1' && l[10] != '2') || (l[11] != ' '))
	// 	return(p_error("kokoko"));
	// base.player = l[10] - 48;
	// // free(l);

	// while (1)
	// {
	// 	// save_input_map(&new);
	// 	// printf("new[%d] = %s\n", i, new.map[i]);

	// 	fprintf(fd, "trtrtrtr\n");
	// 	if (!(new.map = save_input_map(&new)))
	// 		return(p_error("kekeke"));
	// 	if (!(new.piece = save_input_piece(&new)))
	// 		return(p_error("kekeke"));
	// 	ft_next_move(&new, &base);
	// 	printf("%d %d\n", new.yres, new.xres);

	// }
	// printf("%d\n", new.x);
	// printf("%d\n", new.y);
	// printf("%d\n", base.player);

	// system("leaks mkotytsk.filler");
    return 0;
}


