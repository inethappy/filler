#include "filler.h"

char *valid(char *l, t_input *new, char *chr, int x)
{
	int j = -1;
	char *str;
	int k;
	// FILE *fd;
	// fd = fopen("tr.txt", "a");

	str = NULL;
	k = new->i;
	str = ft_strnew(x);
	while (l[++k])
	{
		if (!ft_strchr(chr, l[k]) || j > x)
			return (NULL);
		str[++j] = l[k];
	}
	str[++j] = '\0';
	if (j < (x - 1))
		return (NULL);
	return (str);
}

int p_error(char *s)
{
	ft_printf("%s\n", s);
	return (0);
}

char **save_input_map(t_input *new)
{
	char **xy;
    char *l;
	int i;

	if (!get_next_line(0, &l))
		return NULL;
	free(l);
	while (i < new->ym)
	{
		get_next_line(0, &l);
		new->map[i] = ft_strdup(l + 4);
		i++;
		ft_strdel(&l);
	}
	new->map[i] = NULL;
	return (new->map);
}

char **save_input_piece(t_input *new)
{
	char **xy;
    char *l;
	int i;
	// FILE *fd;

	// fd = fopen("tr.txt", "a");
	i = 0;
	new->i = -1;
	get_next_line(0, &l);
	// fprintf(fd, "in save_input_piece %s\n", l);// ft_strdel(xy);
	i = 0;
	if (ft_strlen(l) <= 8)
	{
		if (l)
			ft_strdel(&l);
		return (NULL);
	}
	xy = ft_strsplit((l + 6), 32);
	new->x = ft_atoi(xy[1]);
	new->y = ft_atoi(xy[0]);
	new->piece = (char**)malloc(sizeof(char*) * new->y + 1);
	ft_strdel(&l);
	free(xy[0]);
	free(xy[1]);
	free(xy);
	while (i < new->y)
	{
		get_next_line(0, &l);
		new->piece[i] = ft_strdup(l);
		i++;
		ft_strdel(&l);
	}
	new->piece[i] = NULL;
	return (new->piece);
}
