#include "filler.h"

int		make_move(t_filler *filler)
{
	if (read_map_size(filler) != 0)
		return (0);
	else if (read_map(filler) != 0)
		return (0);
	else if (read_token_size(filler) != 0)
		return (0);
	else if (read_token(filler) != 0)
		return (0);
	else
		return (solve(filler));
}

int		main(void)
{
	char		*line;
	t_filler	filler;

	ft_bzero(&filler, sizeof(filler));
	if (get_next_line(0, &line) > 0)
	{
		if (!ft_strnequ("$$$ exec p", line, 10))
		{
			free(line);
			return (1);
		}
		filler.player = (char)(line[10] == '1' ? 'O' : 'X');
		filler.enemy = (char)(filler.player == 'X' ? 'O' : 'X');
		free(line);
	}
	while (make_move(&filler) == 1)
		;
	return (0);
}
