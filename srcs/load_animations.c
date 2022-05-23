#include "so_long.h"

int	load_player_anim(t_data *data)
{
	int	w;
	int	h;

	data->game.p_anim_r[0] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox_r1b.xpm", &w, &h);
	data->game.p_anim_r[1] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox_r2b.xpm", &w, &h);
	data->game.p_anim_r[2] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox_r3b.xpm", &w, &h);
	data->game.p_anim_r[3] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox_r4b.xpm", &w, &h);
	data->game.p_anim_r[4] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox_r5b.xpm", &w, &h);
	return (0);
}

int	load_player_sleep(t_data *data)
{
	int	w;
	int	h;

	data->game.p_anim_s[0] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox_s0.xpm", &w, &h);
	data->game.p_anim_s[2] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox_s2.xpm", &w, &h);
	data->game.p_anim_s[1] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox_s1.xpm", &w, &h);
	data->game.p_anim_s[3] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox_s3.xpm", &w, &h);
	data->game.p_anim_s[4] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox_s4.xpm", &w, &h);
	data->game.p_anim_s[5] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox_s5.xpm", &w, &h);
	return (0);
}

int	load_enemy_main_anim(t_data *data)
{
	int	w;
	int	h;

	data->game.enemy_anim[0] = mlx_xpm_file_to_image(
			data->mlx, "./images/blob_anim0b.xpm", &w, &h);
	data->game.enemy_anim[1] = mlx_xpm_file_to_image(
			data->mlx, "./images/blob_anim1b.xpm", &w, &h);
	data->game.enemy_anim[2] = mlx_xpm_file_to_image(
			data->mlx, "./images/blob_anim2b.xpm", &w, &h);
	data->game.enemy_anim[3] = mlx_xpm_file_to_image(
			data->mlx, "./images/blob_anim3b.xpm", &w, &h);
	data->game.enemy_anim[4] = mlx_xpm_file_to_image(
			data->mlx, "./images/blob_anim4b.xpm", &w, &h);
	data->game.enemy_anim[5] = mlx_xpm_file_to_image(
			data->mlx, "./images/blob_anim5b.xpm", &w, &h);
	return (0);
}

int	load_animations(t_data *data)
{
	load_player_anim(data);
	load_player_sleep(data);
	load_enemy_main_anim(data);
	return (0);
}