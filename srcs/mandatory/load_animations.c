#include "so_long.h"

int	load_player_anim1(t_data *data)
{
	int	w;
	int	h;

	data->game.p_anim_r[0] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/idle/fox-idle-r-1.xpm", &w, &h);
	data->game.p_anim_l[0] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/idle/fox-idle-l-1.xpm", &w, &h);
	return (0);
}

int	load_animations(t_data *data)
{
	load_player_anim1(data);
	return (0);
}