#include "filler.h"
#include <limits.h>

static int			check_elem(t_filler *filler, char try_obj, t_elem try,
						int *covers)
{
	if (try.y < 0 || try.x < 0
		|| try.y >= filler->elem_map.y
		|| try.x >= filler->elem_map.x
		|| (try_obj != filler->player
			&& try_obj != filler->player + 32
			&& try_obj != '.'))
		return (0);
	if (try_obj == filler->player || try_obj == filler->player + 32)
		(*covers)++;
	return (*covers < 2);
}

static int			attempt_place_token(t_filler *filler, t_elem current)
{
	t_elem	iterator;
	t_elem	try;
	int		covers;

	covers = 0;
	iterator.y = -1;
	while (++iterator.y < filler->elem_token.y)
	{
		iterator.x = -1;
		while (++iterator.x < filler->elem_token.x)
		{
			if (filler->token[iterator.y][iterator.x] == '*')
			{
				try = set_point(iterator.x + current.x, iterator.y + current.y);
				if (try.x >= filler->elem_map.x || try.y >= filler->elem_map.y)
					return (0);
				if (!check_elem(filler, filler->map[try.y][try.x],
								try, &covers))
					return (0);
			}
		}
	}
	return (covers == 1);
}

static unsigned		distance(t_filler *filler, t_elem player, t_elem enemy)
{
	t_elem		iterator;
	t_elem		cur;
	unsigned	dist;

	iterator.y = -1;
	dist = 0;
	while (++iterator.y < filler->elem_token.y)
	{
		iterator.x = -1;
		while (++iterator.x < filler->elem_token.x)
		{
			if (filler->token[iterator.y][iterator.x] == '*')
			{
				cur = set_point(player.x + iterator.x, player.y + iterator.y);
				dist += (ft_abs(enemy.x - cur.x) + ft_abs(enemy.y - cur.y));
			}
		}
	}
	return (dist);
}

static unsigned		best_distance(t_filler *filler, t_elem player)
{
	t_elem		iterator;
	unsigned	curr;
	unsigned	best;

	best = INT_MAX;
	iterator.y = -1;
	while (++iterator.y < filler->elem_map.y)
	{
		iterator.x = -1;
		while (++iterator.x < filler->elem_map.x)
		{
			if (filler->map[iterator.y][iterator.x] == filler->enemy ||
				filler->map[iterator.y][iterator.x] == filler->enemy + 32)
			{
				if ((curr = distance(filler, player, iterator)) < best)
					best = curr;
			}
		}
	}
	return (best);
}

int					solve(t_filler *filler)
{
	t_elem		answer;
	t_elem		iterator;
	unsigned	curr;
	unsigned	best;

	answer = set_point(-1, -1);
	best = INT_MAX;
	iterator.y = -1 - filler->shape.y;
	while (++iterator.y < filler->elem_map.y)
	{
		iterator.x = -1 - filler->shape.x;
		while (++iterator.x < filler->elem_map.x)
		{
			if (attempt_place_token(filler, iterator))
			{
				if ((curr = best_distance(filler, iterator)) < best)
				{
					best = curr;
					answer = iterator;
				}
			}
		}
	}
	free_struct(filler);
	return (print_answer(answer));
}
