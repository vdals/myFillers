#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct	s_elem
{
	int			x;
	int			y;
}				t_elem;

typedef struct	s_filler
{
	char		player;
	char		enemy;
	t_elem		elem_map;
	t_elem		elem_token;
	t_elem		shape;
	char		**map;
	char		**token;
}				t_filler;

int				solve(t_filler *filler);
int				read_map_size(t_filler *filler);
t_elem			set_point(int x, int y);
int				print_answer(t_elem answer);
int				read_token(t_filler *filler);
int				read_token_size(t_filler *filler);
int				read_map(t_filler *filler);
int				make_move(t_filler *filler);
void			free_struct(t_filler *filler);

#endif
