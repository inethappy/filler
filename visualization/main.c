/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:28:17 by mkotytsk          #+#    #+#             */
/*   Updated: 2019/04/12 12:28:19 by mkotytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		p_error(char *s)
{
	ft_printf("%s\n", s);
	exit(0);
}

void	put_str(t_strct *all, char *l, int i)
{
	int j;
	int k;

	j = 0;
	i = (i == 0) ? i : i * 12;
	while (l[j])
	{
		if (l[j] == 'o' || l[j] == 'O')
		{
			k = (j == 4) ? (5) : ((j - 4) * all->r->mlt + 5);
			if (l[j] == 'O')
				mlx_string_put(all->mlx, all->win_ptr, k, i, 0xfdff, "O");
			else
				mlx_string_put(all->mlx, all->win_ptr, k, i, 0xFFFF00, "O");
		}
		else if (l[j] == 'x' || l[j] == 'X')
		{
			k = (j == 4) ? (5) : ((j - 4) * all->r->mlt + 5);
			if (l[j] == 'X')
				mlx_string_put(all->mlx, all->win_ptr, k, i, 0xff05ff, "X");
			else
				mlx_string_put(all->mlx, all->win_ptr, k, i, 0xFFFF00, "X");
		}
		j++;
	}
}

void	put_winner(t_strct *all, char *l)
{
	int res_o;
	int res_x;

	res_o = ft_atoi(l + 10);
	free(l);
	get_next_line(0, &l);
	res_x = ft_atoi(l + 10);
	if ((all->r->pl == 1 && res_o > res_x)
		|| (all->r->pl == 2 && res_o < res_x))
		mlx_string_put(all->mlx, all->win_ptr, (all->r->width / 2 - 60),
			all->r->height - 25, 0xFFFF00, "You win! :)");
	else
		mlx_string_put(all->mlx, all->win_ptr, (all->r->width / 2 - 60),
			all->r->height - 25, 0xFFFF00, "You lose! :(");
}

void	handle_new_block(int *i, t_strct *all)
{
	*i = -1;
	mlx_do_sync(all->mlx);
	mlx_clear_window(all->mlx, all->win_ptr);
}

int		main(void)
{
	char	*l;
	t_strct	*all;
	int		i;

	all = ft_memalloc(sizeof(t_strct));
	all->r = ft_memalloc(sizeof(t_fill));
	settings(all->r);
	new_img(all, all->r);
	i = 0;
	while (get_next_line(0, &l))
	{
		if (l[0] == '0')
			put_str(all, l, i);
		if (l[0] == ' ')
			handle_new_block(&i, all);
		if (l[0] == '=')
			put_winner(all, l);
		free(l);
		i++;
	}
	mlx_loop(all->mlx);
	return (0);
}
