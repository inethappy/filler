#include "filler.h"

int calculate(t_filler *base, t_input *new, int je, int ie, int jp, int ip)
{
	int d = 0;
	int jmb = new->jm;
	int imb = new->im;
	int bip;

	bip = ip;
	ip = 0;
	jp = 0;
	while (base->piece[jp])
	{
		while (base->piece[jp][ip])
		{
			if (base->piece[jp][ip] == '*')
			{
				d += ABS(je - jmb) + ABS(ie - imb);
				imb++;// += (new->player == 1) ? 1 : -1;
			}
			ip++;
		}
		jp++;
		ip = 0;
		jmb++;// += (new->player == 1) ? 1 : -1;;
	}
	return d;
}

void search_path(t_filler *base, t_input *new, int cjp, int cip)
{
	int j = 0;
	int i = 0;
	int d = 0;

	while (base->map[j] != NULL)
	{
		while (base->map[j][i])
		{
			if (ft_strchr(base->bot, base->map[j][i]))
			{
				// d = ABS(j - new->jm) + ABS(i - new->im);
				d = calculate(base, new, j, i, cjp, cip);
				new->min_d = (new->min_d == -1) ? (d + 1) : new->min_d;
				if (new->min_d > d)
				{
					new->min_d = d;
					new->xres = ABS(new->im - cip);
					new->yres = ABS(new->jm - cjp);
				}
			}
			i++;
		}
		i = 0;
		j++;
	}
}

int check_figure(t_filler *base, t_input *new, int *jp, int *ip)
{
	int j;
	int i;
	int bi;

	i = new->im;
	j = new->jm;
	i = i - *ip;
	j = j - *jp;
	if (i < 0 || j < 0)
		return (0);
	*ip = -1;
	*jp = -1;
	bi = i;
	while (base->map[j] && (++*jp < new->y))
	{
		while (base->map[j][i] && (++*ip < new->x))
		{
			if (((ft_strchr(base->me, base->map[j][i])
				|| ft_strchr(base->bot, base->map[j][i]))
				&& base->piece[*jp][*ip] != '.'))
				return (0);
			i++;
		}
		if (!base->map[j][i])
			break ;
		j++;
		i = bi;
		*ip = -1;
	}
	return (1);
}

int check_tail(t_filler *base, t_input *new, int jp, int ip)
{
	if (ip < (new->x) && ip > -1)
	{
		while (base->piece[jp][ip])
		{
			if (base->piece[jp][ip] == 42)
				return (0);
			ip++;
			break ;
		}
		jp++;
	}
	if (jp < (new->y))
	{
		while (jp < new->y)
		{
			if (ft_strchr(base->piece[jp], 42))
				return (0);
			jp++;
		}
	}
	return (1);
}

int check(t_filler *base, t_input *new, int jp, int ip)
{
	base->map[new->jm][new->im] = 'a';
	if (!check_figure(base, new, &jp, &ip) || !check_tail(base, new, jp, ip))
	{
		base->map[new->jm][new->im] = (new->player == 1) ? 'O' : 'X';
		return (0);
	}
	base->map[new->jm][new->im] = (new->player == 1) ? 'O' : 'X';
	return (1);
}
