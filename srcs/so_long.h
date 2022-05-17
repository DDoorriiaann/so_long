#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/libft.h"
# include <unistd.h>

typedef struct	s_game
{
	void		*grass;
	//void		*player_l;
	//void		*player_r;
	void		*p_anim_r[5];
	int			player_h;
	int			player_w;
}	t_game;



typedef struct	s_data
{
	void	*mlx;
	void	*mlx_win;
	t_game	game;
	int		frame;
}	t_data;

void	move_player(t_data *data,int x_offset, int y_offset);
int	clock(t_data *data);
int	deal_key(int key, t_data *data);

#endif