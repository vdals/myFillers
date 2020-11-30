#include "filler.h"
#include <limits.h>

int	read_token(t_filler *fill)
{
	char			*line;
	register int	x;
	register int	y;

	fill->shape = set_point(INT_MAX, INT_MAX);
	y = -1;
	fill->token = (char**)malloc(sizeof(char*) * fill->elem_token.y);
	while (++y < fill->elem_token.y)
	{
		if (get_next_line(0, &line) > 0)
		{
			x = -1;
			fill->token[y] = (char*)malloc(sizeof(char) * fill->elem_token.x);
			while (++x < fill->elem_token.x)
			{
				if (line[x] == '*' && fill->shape.y > y)
					fill->shape.y = y;
				if (line[x] == '*' && fill->shape.x > x)
					fill->shape.x = x;
				fill->token[y][x] = line[x];
			}
			free(line);
		}
	}
	return (0);
}

int	read_token_size(t_filler *filler)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) > 0)
	{
		if (!ft_strnequ("Piece", line, 5))
			return (1);
		tmp = ft_strchr(line, ' ');
		filler->elem_token.y = ft_atoi(++tmp);
		tmp = ft_strchr(tmp, ' ');
		filler->elem_token.x = ft_atoi(++tmp);
		free(line);
	}
	else
		return (1);
	return (0);
}

int	read_map(t_filler *filler)
{
	char			*line;
	register int	x;
	register int	y;

	y = -1;
	filler->map = (char**)malloc(sizeof(char*) * filler->elem_map.y);
	while (++y < filler->elem_map.y)
	{
		if (get_next_line(0, &line) > 0)
		{
			x = -1;
			filler->map[y] = (char*)malloc(sizeof(char) * filler->elem_map.x);
			while (++x < filler->elem_map.x)
				filler->map[y][x] = line[x + 4];
			free(line);
		}
	}
	return (0);
}

int	read_map_size(t_filler *filler)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) > 0)
	{
		if (!ft_strnequ("Plateau", line, 7))
			return (1);
		tmp = ft_strchr(line, ' ');
		filler->elem_map.y = ft_atoi(++tmp);
		tmp = ft_strchr(tmp, ' ');
		filler->elem_map.x = ft_atoi(++tmp);
		free(line);
		if (get_next_line(0, &line) > 0)
			free(line);
	}
	else
		return (1);
	return (0);
}
