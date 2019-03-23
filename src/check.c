/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 12:35:41 by mkotytsk          #+#    #+#             */
/*   Updated: 2019/03/23 12:35:43 by mkotytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		calculate(t_filler *base, t_input *new, int jp, int ip)
{
	int d;
	int jmb;
	int imb;
	int bip;

	d = 0;
	jmb = new->jm;
	imb = new->im;
	bip = ip;
	ip = -1;
	jp = -1;
	while (base->piece[++jp])
	{
		while (base->piece[jp][++ip])
		{
			if (base->piece[jp][ip] == '*')
			{
				d += ABS(new->j_tmp - jmb) + ABS(new->i_tmp - imb);
				imb += -1;
			}
		}
		ip = -1;
		jmb++;
	}
	return (d);
}

void	search_path(t_filler *base, t_input *new, int cjp, int cip)
{
	int d;

	new->j_tmp = 0;
	new->i_tmp = 0;
	d = 0;
	while (base->map[new->j_tmp] != NULL)
	{
		while (base->map[new->j_tmp][new->i_tmp])
		{
			if (ft_strchr(base->bot, base->map[new->j_tmp][new->i_tmp]))
			{
				d = calculate(base, new, cjp, cip);
				new->min_d = (new->min_d == -1) ? (d + 1) : new->min_d;
				if (new->min_d > d)
				{
					new->min_d = d;
					new->xres = ABS(new->im - cip);
					new->yres = ABS(new->jm - cjp);
				}
			}
			new->i_tmp++;
		}
		new->i_tmp = 0;
		new->j_tmp++;
	}
}

int		check_figure(t_filler *base, t_input *new, int *jp, int *ip)
{
	int bi;

	new->i_tmp = new->im - *ip;
	new->j_tmp = new->jm - *jp;
	if (new->i_tmp < 0 || new->j_tmp < 0)
		return (0);
	*jp = -1;
	bi = new->i_tmp;
	while (base->map[new->j_tmp] && (++*jp < new->y) && (*ip = -1))
	{
		while (base->map[new->j_tmp][new->i_tmp] && (++*ip < new->x))
		{
			if (((ft_strchr(base->me, base->map[new->j_tmp][new->i_tmp])
				|| ft_strchr(base->bot, base->map[new->j_tmp][new->i_tmp]))
				&& base->piece[*jp][*ip] != '.'))
				return (0);
			new->i_tmp++;
		}
		if (!base->map[new->j_tmp][new->i_tmp])
			break ;
		new->j_tmp++;
		new->i_tmp = bi;
	}
	return (1);
}

int		check_tail(t_filler *base, t_input *new, int jp, int ip)
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

int		check(t_filler *base, t_input *new, int jp, int ip)
{
	base->map[new->jm][new->im] = 'a';
	new->j_tmp = new->jm;
	new->i_tmp = new->im;
	if (!check_figure(base, new, &jp, &ip) || !check_tail(base, new, jp, ip))
	{
		base->map[new->jm][new->im] = (new->player == 1) ? 'O' : 'X';
		return (0);
	}
	base->map[new->jm][new->im] = (new->player == 1) ? 'O' : 'X';
	return (1);
}
