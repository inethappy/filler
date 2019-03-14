#include "filler.h"

void ft_next_move(t_input *new, t_filler *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	base->me = (base->player == 1) ? ft_strdup("oO") : ft_strdup("xX");
	base->bot = (base->player == 1) ? ft_strdup("xX") : ft_strdup("oO");
	while (new->map[j])
	{


	}

}

int main(void)
{
    char *l;
    int i = 0;

	t_filler base;
	char **xy;
	t_input new;

	ft_bzero(&new, sizeof(new));
	ft_bzero(&base, sizeof(t_filler));
	get_next_line(0, &l);
	if (!l[10] || (l[10] != '1' && l[10] != '2') || (l[11] != ' '))
		return(p_error("kokoko"));
	base.player = l[10] - 48;
	free(l);
	while (1)
	{
		if (!(new.map = save_input_map(&new)))
			return(p_error("kekeke"));
		if (!(new.piece = save_input_piece(&new)))
			return(p_error("kekeke"));
		ft_next_move(&new, &base);
	}
	// printf("%d\n", new.x);
	// printf("%d\n", new.y);
	// printf("%d\n", base.player);

	// system("leaks mkotytsk.filler");
    return 0;
}


