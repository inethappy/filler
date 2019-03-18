#include "filler.h"

char *valid(char *l, t_input *new, char *chr, int x)
{
	int j = -1;
	char *str;
	int k;
	FILE *fd;
	fd = fopen("tr.txt", "a");

	// fprintf(fd, "---wfkwfwjfwlfjlws\n");
	// fprintf(fd, "!!!%s\n", l);
	k = new->i;
	str = ft_strnew(x + 1);
	while (l[++k])
	{
	// fprintf(fd, "---!!!%s\n", l);
		if (!ft_strchr(chr, l[k]) || j > x)
			return (NULL);
		str[++j] = l[k];
	// fprintf(fd, "$$$%c\n", l[k]);
	}
	str[++j] = '\0';
	// fprintf(fd, "---!!!j = %d, new->x = %d, l = %c\n", j, new->x, l[k]);
	// fprintf(fd, "@@!!!%s\n", l);
	if (j < (x - 1))
		return (NULL);
	free(l);
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

	FILE *fd;
	fd = fopen("tr.txt", "a");

	new->i = 3;
	get_next_line(0, &l);
	fprintf(fd, "---%s\n", l);
	i = 0;
	if (ft_strlen(l) <= 10)
		return (NULL);
	xy = ft_strsplit((l + 8), 32);
	new->xm = ft_atoi(xy[1]);
	new->ym = ft_atoi(xy[0]);
	fprintf(fd, "---%d\n", new->ym);
	free(l);
	get_next_line(0, &l);
	free(l);
	new->map = (char**)malloc(sizeof(char*) * new->ym + 1);
	while (i < new->ym)
	{
		get_next_line(0, &l);
		if (!(new->map[i] = valid(l, new, ".oOxX", new->xm)))
			return (NULL);
		// printf("new[%d] = %s\n", i, new->map[i]);
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
	// FILE *fd;

	// fd = fopen("tr.txt", "a");
	i = 0;
	new->i = -1;
	get_next_line(0, &l);
	// fprintf(fd, "in save_input_piece %s\n", l);// ft_strdel(xy);
	i = 0;
	if (ft_strlen(l) <= 8)
		return (NULL);
	xy = ft_strsplit((l + 6), 32);
	new->x = ft_atoi(xy[1]);
	new->y = ft_atoi(xy[0]);
	new->piece = (char**)malloc(sizeof(char*) * new->y + 1);
	while (i < new->y)
	{
		get_next_line(0, &l);
		if (!(new->piece[i] = valid(l, new, ".*", new->x)))
			return(NULL);
		// printf("piece[%d] = %s\n", i, new->piece[i]);
		i++;
	}
	// fprintf(fd, "+++ %s\n", l);// ft_strdel(xy);
	new->piece[i] = NULL;
	return (new->piece);
}
