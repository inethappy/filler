#include "filler.h"

char *valid(char *l, t_input *new, char *chr)
{
	int j = -1;
	char *str;
	int k;

	k = new->i;
	str = ft_strnew(new->x + 1);
	while (l[++k])
	{
		if (!ft_strchr(chr, l[k]) || j > new->x)
			return (NULL);
		str[++j] = l[k];
	}
	str[++j] = '\0';
	if (j < new->x)
		return (NULL);
	free(l);
	return (str);
}

int p_error(char *s)
{
	ft_printf("%s\n", s);
	return (1);
}

char **save_input_map(t_input *new)
{
	char **xy;
    char *l;
	int i;

	i = 0;
	new->i = 3;
	get_next_line(0, &l);
	xy = ft_strsplit((l + 8), 32);
	new->x = ft_atoi(xy[1]);
	new->y = ft_atoi(xy[0]);
	free(l);
	get_next_line(0, &l);
	free(l);
	// ft_strdel(xy);
	new->map = (char**)malloc(sizeof(char*) * new->y + 1);
	while (i < new->y)
	{
		get_next_line(0, &l);
		if (!(new->map[i] = valid(l, new, ".oOxX")))
			return (NULL);
		// printf("new[%d] = %s\n", i, xy[i]);
		i++;
	}
	new->map[i] = NULL;
	return (new->map);
}

char **save_input_piece(t_input *new)
{
	char **xy;
    char *l;
	int i;

	i = 0;
	new->i = -1;
	get_next_line(0, &l);
	// ft_strdel(xy);
	i = 0;
	xy = ft_strsplit((l + 6), 32);
	new->x = ft_atoi(xy[1]);
	new->y = ft_atoi(xy[0]);
	new->piece = (char**)malloc(sizeof(char*) * new->y + 1);
	while (i < new->y)
	{
		get_next_line(0, &l);
		if (!(new->piece[i] = valid(l, new, ".*")))
			return(NULL);
		// printf("piece[%d] = %s\n", i, new->piece[i]);
		i++;
	}
	new->piece[i] = NULL;
	return (new->piece);
}
