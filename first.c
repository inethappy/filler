#include "libft/libft.h"
#include "filler.h"
#include <stdio.h>


char *valid(char *l, t_map *map, char *chr)
{
	int j = -1;
	char *str;


	// if (ft_strlen(l) != (map->x + 4))
	// 	return (NULL);
	str = ft_strnew(map->x + 1);
	while (l[++map->i])
	{
		if (!ft_strchr(chr, l[map->i]) || j > map->x)
			return (NULL);
		str[++j] = l[map->i];
	}
	str[++j] = '\0';
	free(l);
	return (str);
}

int p_error(char *s)
{
	printf("%s\n", s);
	return (1);
}

int main()
{
    char *l;
    int i = 0;

	t_filler base;
	char **xy;
	t_map map;

	ft_bzero(&map, sizeof(map));
	ft_bzero(&base, sizeof(t_filler));
	get_next_line(0, &l);
	if (!l[10] || (l[10] != '1' && l[10] != '2'))
		return(p_error("kokoko"));
	base.player = l[10] - 48;
	free(l);
	get_next_line(0, &l);
	xy = ft_strsplit((l + 8), 32);
	map.x = ft_atoi(xy[1]);
	map.y = ft_atoi(xy[0]);
	free(l);
	get_next_line(0, &l);
	free(l);
	map.new = (char**)malloc(sizeof(char*) * map.y + 1);
	while (i < map.y)
	{
		map.i = 3;
		get_next_line(0, &l);
		if (!(map.new[i] = valid(l, &map, ".oOxX")))
			return(p_error("kekeke"));
		// printf("map[%d] = %s\n", i, map.new[i]);
		i++;
	}
	get_next_line(0, &l);
	ft_strdel(xy);
	i = 0;
	xy = ft_strsplit((l + 6), 32);
	map.x = ft_atoi(xy[1]);
	map.y = ft_atoi(xy[0]);
	map.piece = (char**)malloc(sizeof(char*) * map.y + 1);
	while (i < map.y)
	{
		map.i = -1;
		get_next_line(0, &l);
		if (!(map.piece[i] = valid(l, &map, ".*")))
			return(p_error("kekeke"));
		printf("map[%d] = %s\n", i, map.piece[i]);
		i++;
	}

	// printf("%d\n", map.x);
	// printf("%d\n", map.y);
	// printf("%d\n", base.player);

	// while (i < 100)
	// {
	// 	get_next_line(0, &l);

	// 	// printf("%s\n", l);
	// 	free(l);
	// 	i++;
	// }
    // close(fd);
	// system("leaks mkotytsk.filler");
    return 0;
}


