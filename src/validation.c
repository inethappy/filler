/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 12:42:26 by mkotytsk          #+#    #+#             */
/*   Updated: 2019/03/23 12:42:28 by mkotytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	p_error(char *s)
{
	ft_printf("%s\n", s);
	return (0);
}

int	save_input_map(t_input *new, t_filler *base)
{
	char	*l;
	int		i;

	if (!get_next_line(0, &l))
		return (0);
	free(l);
	i = 0;
	while (i < new->ym)
	{
		if (get_next_line(0, &l) <= 0)
			return (0);
		base->map[i] = ft_strcpy(base->map[i], (l + 4));
		free(l);
		i++;
	}
	return (1);
}

int	save_input_piece(t_input *new, t_filler *base)
{
	char	*l;
	int		i;

	if (!get_next_line(0, &l))
		return (0);
	new->y = ft_atoi(l + 6);
	new->x = ft_atoi(l + (ft_strrchr(l, ' ') - l));
	ft_strdel(&l);
	i = -1;
	while (++i < new->y)
	{
		if (get_next_line(0, &l) <= 0)
			return (0);
		base->piece[i] = ft_strcpy(base->piece[i], l);
		free(l);
	}
	while (base->piece[i])
	{
		ft_bzero(base->piece[i], ft_strlen(base->piece[i]));
		i++;
	}
	return (1);
}
