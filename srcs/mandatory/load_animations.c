#include "so_long.h"

int	load_player_anim1(t_data *data)
{
	int	w;
	int	h;

	data->game.p_anim_r[0] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/idle/fox-idle-r-1.xpm", &w, &h);
	data->game.p_anim_r[1] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/idle/fox-idle-r-2.xpm", &w, &h);
	data->game.p_anim_r[2] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/idle/fox-idle-r-3.xpm", &w, &h);
	data->game.p_anim_r[3] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/idle/fox-idle-r-4.xpm", &w, &h);
	data->game.p_anim_r[4] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/idle/fox-idle-r-5.xpm", &w, &h);
	data->game.p_anim_l[0] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/idle/fox-idle-l-1.xpm", &w, &h);
	data->game.p_anim_l[1] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/idle/fox-idle-l-2.xpm", &w, &h);
	data->game.p_anim_l[2] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/idle/fox-idle-l-3.xpm", &w, &h);
	data->game.p_anim_l[3] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/idle/fox-idle-l-4.xpm", &w, &h);
	data->game.p_anim_l[4] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/idle/fox-idle-l-5.xpm", &w, &h);
	return (0);
}

int	load_player_sleep(t_data *data)
{
	int	w;
	int	h;

	data->game.p_anim_s[0] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/sleep/fox-sleep-1.xpm", &w, &h);
	data->game.p_anim_s[2] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/sleep/fox-sleep-2.xpm", &w, &h);
	data->game.p_anim_s[1] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/sleep/fox-sleep-3.xpm", &w, &h);
	data->game.p_anim_s[3] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/sleep/fox-sleep-4.xpm", &w, &h);
	data->game.p_anim_s[4] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/sleep/fox-sleep-5.xpm", &w, &h);
	data->game.p_anim_s[5] = mlx_xpm_file_to_image(
			data->mlx, "./images/fox/sleep/fox-sleep-6.xpm", &w, &h);
	return (0);
}

// int	load_enemy_main_anim(t_data *data)
// {
// 	int	w;
// 	int	h;

// 	data->game.enemy_anim[0] = mlx_xpm_file_to_image(
// 			data->mlx, "./images/chicken/idle/chicken-idle-1.xpm", &w, &h);
// 	data->game.enemy_anim[1] = mlx_xpm_file_to_image(
// 			data->mlx, "./images/chicken/idle/chicken-idle-2.xpm", &w, &h);
// 	data->game.enemy_anim[2] = mlx_xpm_file_to_image(
// 			data->mlx, "./images/chicken/idle/chicken-idle-3.xpm", &w, &h);
// 	data->game.enemy_anim[3] = mlx_xpm_file_to_image(
// 			data->mlx, "./images/chicken/idle/chicken-idle-4.xpm", &w, &h);
// 	data->game.enemy_anim[4] = mlx_xpm_file_to_image(
// 			data->mlx, "./images/chicken/idle/chicken-idle-5.xpm", &w, &h);
// 	data->game.enemy_anim[5] = mlx_xpm_file_to_image(
// 			data->mlx, "./images/chicken/idle/chicken-idle-6.xpm", &w, &h);
// 	return (0);
// }

int	load_animations(t_data *data)
{
	load_player_anim1(data);
	load_player_sleep(data);
	//load_enemy_main_anim(data);
	return (0);
}