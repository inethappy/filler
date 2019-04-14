/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:18:55 by mkotytsk          #+#    #+#             */
/*   Updated: 2019/04/12 12:19:08 by mkotytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <mlx.h>
# include "../inc/filler.h"
# include "../inc/ft_printf.h"
# include "../inc/libft.h"

typedef struct	s_fill
{
	int		width;
	int		height;
	int		pl;
	int		en;
	char	**map;
	int		mlt;
}				t_fill;

typedef	struct	s_strct
{
	char	*address;
	void	*mlx;
	void	*win_ptr;
	void	*img;
	void	*param;
	int		bbp;
	int		sl;
	int		end;
	t_fill	*r;
}				t_strct;

int				p_error(char *s);
int				exit_key(int key);
int				redcross(void *param);
void			save_settings(t_fill *read, char *l);
void			settings(t_fill *read);
void			put_str(t_strct *all, char *l, int i);
void			put_winner(t_strct *all, char *l);
void			new_img(t_strct *all, t_fill *r);

#endif
