/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotytsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 12:52:05 by mkotytsk          #+#    #+#             */
/*   Updated: 2019/03/23 12:52:07 by mkotytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define ABS(Value) (((Value) < 0) ? -(Value) : (Value))

typedef struct	s_filler
{
	char *me;
	char *bot;
	char **map;
	char **piece;
}				t_filler;

typedef struct	s_input
{
	int x;
	int xm;
	int y;
	int ym;
	int	player;
	int xres;
	int yres;
	int min_d;
	int jm;
	int im;
	int j_tmp;
	int i_tmp;

}				t_input;

int				save_input_piece(t_input *new, t_filler *base);
int				save_input_map(t_input *new, t_filler *base);
char			*valid(char *l, t_input *new, char *chr, int x);
int				p_error(char *s);
void			save_input(t_input *new, t_filler *base);
int				game(t_input *new, t_filler *base);
void			ft_next_move(t_input *new, t_filler *base);
void			put_piece(t_input *new, t_filler *base);
int				check(t_filler *base, t_input *new, int jp, int ip);
int				check_figure(t_filler *base, t_input *new, int *jp, int *ip);
int				check_tail(t_filler *base, t_input *new, int jp, int ip);
void			search_path(t_filler *base, t_input *new, int cjp, int cip);
int				calculate(t_filler *base, t_input *new, int jp, int ip);

#endif
