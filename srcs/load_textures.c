#include"so_long.h"

int	load_background(t_data *data)
{
	int	w;
	int	h;

	data->game.grass = mlx_xpm_file_to_image(
			data->mlx, "./images/grass.xpm", &w, &h);
	return (0);
}

int	load_wall(t_data *data)
{
	int	w;
	int	h;

	data->game.wall = mlx_xpm_file_to_image(
			data->mlx, "./images/wall.xpm", &w, &h);
	return (0);
}

// int	load_exit(t_data *data)
// {
// 	int	w;
// 	int	h;

// 	data->game.exit = mlx_xpm_file_to_image(
// 			data->mlx, "./images/exit.xpm", &w, &h);
// 	return (0);
// }

int	load_textures(t_data *data)
{
	load_background(data);
	load_wall(data);
	//load_exit(data);
	return (0);
}