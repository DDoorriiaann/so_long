#include"so_long.h"

int	load_background(t_data *data)
{
	int	w;
	int	h;

	data->game.grass = mlx_xpm_file_to_image(
			data->mlx, "./images/grass.xpm", &w, &h);
	return (0);
}

int	load_walls(t_data *data)
{
	int	w;
	int	h;

	data->game.wall = mlx_xpm_file_to_image(
			data->mlx, "./images/walls/wall.xpm", &w, &h);
	return (0);
}

int	load_collectible(t_data *data)
{
	int	w;
	int	h;

	data->game.collectible = mlx_xpm_file_to_image(
			data->mlx, "./images/collectible.xpm", &w, &h);
	return (0);
}

int	load_exit(t_data *data)
{
	int	w;
	int	h;

	data->game.exit[0] = mlx_xpm_file_to_image(
			data->mlx, "./images/exit/exit_closed2.xpm", &w, &h);
	data->game.exit[1] = mlx_xpm_file_to_image(
			data->mlx, "./images/exit/exit_open.xpm", &w, &h);
	data->game.exit[2] = mlx_xpm_file_to_image(
			data->mlx, "./images/exit/exit_game_over.xpm", &w, &h);
	return (0);
}

int	load_textures(t_data *data)
{
	load_background(data);
	load_walls(data);
	load_collectible(data);
	load_exit(data);
	return (0);
}