#include "filler.h"

void search_path(t_filler *base, t_input *new, int cj, int ci)
{
	// if (search_enemy(map, j, i) )
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
				// buf = (j > cj) ? (j - cj)) : (cj - j);
				// d = /*(d > (j - ABS(cj) + (i - ABS(ci)))) ? */(ABS(j - cj) + ABS(i - ci));//: d;
				d = (d == 0) ? (ABS(j - cj) + ABS(i - ci)) : d;
				if (d >= ((ABS(j - cj) + ABS(i - ci))))
				{
					d = ABS(j - cj) + ABS(i - ci);
					new->min_d = (new->min_d == 0) ? d : 0;//new->min_d;
					if (new->min_d < d)
					{
						new->xres = ci;
						new->yres = cj;
					}
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
	int bip;
	i = i - ((new->y - 2) - ip);
	if (i < 0)
		return (0);
	ip = 0;
	bi = i;
	bip = ip;
	while (new->map[j][i] && (jp < new->y))
	{
		while (new->map[j][++i] && (++ip < new->x))
			if (ft_strchr(base->me, new->map[j][i]) && new->piece[jp][ip] != '.')
				return (0);
		j++;
		i = bi;
		ip = 0;
		jp++;
	}
	if (jp < new->y || ip < new->x)
	{
		while (new->piece[jp])
		{
			if (ft_strchr(new->piece[jp], 42))
				return (0);
			jp++;
		}
	}
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
					search_path(base, new, j, i);
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
	base->me = (base->player == 1) ? ft_strdup("oO") : ft_strdup("xX");
	base->bot = (base->player == 1) ? ft_strdup("xX") : ft_strdup("oO");
	// printf("%s\n", new->map[i]);
	// printf("%s\n", new->piece[i]);
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
	printf("%d %d\n", new->xres, new->yres);
}

int main(void)
{
    char *l;
    int i = 0;

	t_filler base;
	char **xy;
	t_input new;

	ft_bzero(&new, sizeof(new));
	ft_bzero(&base, sizeof(t_filler));
	get_next_line(0, &l);
	if (!l[10] || (l[10] != '1' && l[10] != '2') || (l[11] != ' '))
		return(p_error("kokoko"));
	base.player = l[10] - 48;
	free(l);
	while (1)
	{
		// save_input_map(&new);
		// printf("new[%d] = %s\n", i, new.map[i]);

		if (!(new.map = save_input_map(&new)))
			return(p_error("kekeke"));
		if (!(new.piece = save_input_piece(&new)))
			return(p_error("kekeke"));
		ft_next_move(&new, &base);
	}
	// printf("%d\n", new.x);
	// printf("%d\n", new.y);
	// printf("%d\n", base.player);

	// system("leaks mkotytsk.filler");
    return 0;
}


