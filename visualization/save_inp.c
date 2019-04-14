/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_inp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:19:30 by mkotytsk          #+#    #+#             */
/*   Updated: 2019/04/12 12:19:34 by mkotytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		exit_key(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

int		redcross(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	new_img(t_strct *all, t_fill *r)
{
	all->sl = 5;
	all->mlx = mlx_init();
	all->win_ptr = mlx_new_window(all->mlx, r->width, r->height, "FIGHT CLUB");
	all->img = mlx_new_image(all->mlx, r->width, r->height);
	all->address = mlx_get_data_addr(all->img, &all->bbp, &all->sl, &all->end);
	mlx_hook(all->win_ptr, 2, 0, exit_key, all);
	mlx_hook(all->win_ptr, 17, 0, redcross, r);
}

void	save_settings(t_fill *r, char *l)
{
	r->mlt = (ft_atoi(l + 8) > 25) ? 13 : 14;
	r->height = ((ft_atoi(l + 8)) * r->mlt);
	r->width = (ft_atoi(l + 8) > 25) ? ((ft_atoi(l + 8)) * r->mlt + 100)
		: (ft_atoi(l + (ft_strrchr(l, ' ') - l))) * r->mlt;
}

void	settings(t_fill *r)
{
	char *l;

	while (get_next_line(0, &l))
	{
		if (l[0] == '$')
		{
			if (ft_strstr(l, "mkotytsk"))
				r->pl = l[10] - 48;
			else
				r->en = l[10] - 48;
		}
		if (l[0] == 'P' && ft_strstr(l, "Plateau"))
			save_settings(r, l);
		if (ft_strstr(l, "0123456789"))
		{
			free(l);
			break ;
		}
		if (l[0] == 'e')
			p_error("The error is occured.\n");
		free(l);
	}
	if (!r->pl || !r->en)
		p_error("The error is occured.\n");
}
