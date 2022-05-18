#include "so_long.h"

int	load_player_anim(t_data *data)
{
	int	w;
	int	h;

	data->game.p_anim_r[0] = mlx_xpm_file_to_image(data->mlx, "./images/fox_r1.xpm", &w, &h);
	data->game.p_anim_r[1] = mlx_xpm_file_to_image(data->mlx, "./images/fox_r2.xpm", &w, &h);
	data->game.p_anim_r[2] = mlx_xpm_file_to_image(data->mlx, "./images/fox_r3.xpm", &w, &h);
	data->game.p_anim_r[3] = mlx_xpm_file_to_image(data->mlx, "./images/fox_r4.xpm", &w, &h);
	data->game.p_anim_r[4] = mlx_xpm_file_to_image(data->mlx, "./images/fox_r5.xpm", &w, &h);
	return(0);
}

int	load_enemy_main_anim(t_data *data)
{
	int	w;
	int	h;

	data->game.enemy_anim[0] = mlx_xpm_file_to_image(data->mlx, "./images/blob_anim0.xpm", &w, &h);
	data->game.enemy_anim[1] = mlx_xpm_file_to_image(data->mlx, "./images/blob_anim1.xpm", &w, &h);
	data->game.enemy_anim[2] = mlx_xpm_file_to_image(data->mlx, "./images/blob_anim2.xpm", &w, &h);
	data->game.enemy_anim[3] = mlx_xpm_file_to_image(data->mlx, "./images/blob_anim3.xpm", &w, &h);
	data->game.enemy_anim[4] = mlx_xpm_file_to_image(data->mlx, "./images/blob_anim4.xpm", &w, &h);
	data->game.enemy_anim[5] = mlx_xpm_file_to_image(data->mlx, "./images/blob_anim5.xpm", &w, &h);
	return(0);
}

int	load_animations(t_data *data)
{
	load_player_anim(data);
	load_enemy_main_anim(data);
	return(0);
}