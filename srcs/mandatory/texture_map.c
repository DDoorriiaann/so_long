#include "so_long.h"

void	put_background(int w, int h, t_data *data)
{
	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->game.grass, w * 48, h * 48);
}

void	put_wall(int w, int h, t_data *data)
{
	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->game.wall, w * 48, h * 48);
}

void	put_collectible(int w, int h, t_data *data)
{
	data->game.collectibles_nb++;
	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->game.collectible, w * 48, h * 48);
}

void	put_exit(int w, int h, t_data *data)
{
	data->game.exit_coord[0] = h;
	data->game.exit_coord[1] = w;
	if (data->game.exit_status == 0)
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->game.exit[0], w * 48, h * 48);
	if (data->game.exit_status == 1)
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->game.exit[1], w * 48, h * 48);
	if (data->game.exit_status == 2)
		mlx_put_image_to_window(data->mlx,
			data->mlx_win, data->game.exit[2], w * 48, h * 48);
}

void	put_player(int w, int h, t_data *data)
{
	data->game.player_h = h * 48;
	data->game.player_w = w * 48;
}

void	texture_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->h_res)
	{
		while (j < data->w_res)
		{
			if (data->map[i][j] == '0')
				put_background(j, i, data);
			else if (data->map[i][j] == '1')
				put_wall(j, i, data);
			else if (data->map[i][j] == 'C')
				put_collectible(j, i, data);
			else if (data->map[i][j] == 'E')
				put_exit(j, i, data);
			else if (data->map[i][j] == 'P')
				put_player(j, i, data);
			j++;
		}
		j = 0;
		i++;
	}
	update_moves_counter(data);
}