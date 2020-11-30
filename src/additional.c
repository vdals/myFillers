#include "filler.h"

t_elem	set_point(int x, int y)
{
	t_elem	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

void	free_struct(t_filler *filler)
{
	register int		y;

	y = -1;
	while (++y < filler->elem_map.y)
		free(filler->map[y]);
	free(filler->map);
	filler->map = NULL;
	y = -1;
	while (++y < filler->elem_token.y)
		free(filler->token[y]);
	free(filler->token);
	filler->token = NULL;
}

int		print_answer(t_elem answer)
{
	if (answer.y == -1 && answer.x == -1)
	{
		ft_putstr("0 0\n");
		return (0);
	}
	ft_putnbr(answer.y);
	write(1, " ", 1);
	ft_putnbr(answer.x);
	write(1, "\n", 1);
	return (1);
}
