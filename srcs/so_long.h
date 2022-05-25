#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_game
{
	void		*grass;
	void		*wall;
	void		*exit;
	int			player_dir;
	void		*p_anim_r[5];
	void		*p_anim_l[5];
	void		*p_anim_s[6];
	int			player_h;
	int			player_w;
	void		*enemy_anim[6];
	int			enemies_nb;
	int			enemies_h[20];
	int			enemies_w[20];
}	t_game;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		w_res;
	int		h_res;
	t_game	game;
	int		frame;
	int		idle_time;
}	t_data;

int		parse_map(char *filename, t_data *data);
void	move_player(t_data *data, int x_offset, int y_offset);
void	move_enemies(t_data *data);
int		clock(t_data *data);
int		ft_rand(void);
int		deal_key(int key, t_data *data);
int		load_animations(t_data *data);
int		load_enemies(t_data *data);
int		load_textures(t_data *data);
void	texture_map(t_data *data);
void	player_frame(t_data *data);
void	throw_error(int error);

#endif