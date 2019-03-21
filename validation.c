#include "filler.h"

int p_error(char *s)
{
	ft_printf("%s\n", s);
	return (0);
}

int save_input_map(t_input *new)
{
	char **xy;
    char *l;
	int i;

	if (!get_next_line(0, &l))
	{
		ft_strdel(&l);
		return 0;
	}
	free(l);//	ft_strdel(&l);
	while (i < new->ym)
	{
		if (get_next_line(0, &l) <= 0)
		{
			free(l);
			return 0;
		}
		new->map[i] = ft_strcpy(new->map[i], (l + 4));
		free(l);
		i++;
	}
	return (1);
}

int save_input_piece(t_input *new)
{
	char **xy;
    char *l;
	int i;

	FILE *fd;

	fd = fopen("test1.txt", "a");
	i = 0;
	new->i = -1;
	if (!get_next_line(0, &l))
	{
		ft_strdel(&l);
		return 0;
	}
   	new->y = ft_atoi(l + 6);
	new->x = ft_atoi(l + (ft_strrchr(l, ' ') - l));
	ft_strdel(&l);
	i = 0;
  	while (i < new->y)
	{
		if (get_next_line(0, &l) <= 0)
		{
			free(l);
			return 0;
		}
		new->piece[i] = ft_strcpy(new->piece[i], l);
		free(l);
		i++;
	}
	while (new->piece[i])
	{
		ft_bzero(new->piece[i], ft_strlen(new->piece[i]));
		i++;
	}
	return (1);
}
