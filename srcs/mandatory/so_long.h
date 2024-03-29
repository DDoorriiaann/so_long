/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:29:36 by dguet             #+#    #+#             */
/*   Updated: 2022/07/05 17:30:48 by dguet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_game
{
	void		*collectible;
	void		*grass;
	void		*wall;
	void		*exit[3];
	int			exit_coord[2];
	int			exit_status;
	int			player_dir;
	void		*p_anim_r[1];
	void		*p_anim_l[1];
	int			player_h;
	int			player_w;
	void		*collectible_anim[1];
	int			collectibles_nb;
	int			collectibles_h[100];
	int			collectibles_w[100];
}	t_game;

typedef enum error
{
	NO_ERROR,
	CORRUPTED_FILE,
	WRONG_LINE_LENGTH,
	MALLOC_ERROR,
	MAP_TOO_SMALL,
	MAP_BORDER_ERROR,
	UNKNOWN_MAP_ELEMENT,
	WRONG_FILE_EXTENSION,
	INVALID_MAP,
}	t_error;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		w_res;
	int		h_res;
	int		moves;
	t_game	game;
	int		frame;
	int		idle_time;
	t_error	error;
}	t_data;

typedef struct s_mapcheck
{
	int	p_count;
	int	c_count;
	int	e_count;
	int	x;
	int	y;
}	t_map_check;

typedef struct s_errordesc
{
	int		code;
	char	*message;
}	t_errordesc;

void		parse_map(char *filename, t_data *data);
void		move_player(t_data *data, int x_offset, int y_offset);
void		move_player_up(t_data *data);
void		move_player_down(t_data *data);
void		move_player_left(t_data *data);
void		move_player_right(t_data *data);
void		put_background(int w, int h, t_data *data);
void		put_wall(int w, int h, t_data *data);
void		put_exit(int w, int h, t_data *data);
void		put_collectible(int w, int h, t_data *data);
void		put_player(int w, int h, t_data *data);
int			update_exit(t_data *data, int code);
int			update_moves_counter(t_data *data);
int			remove_collectible(t_data *data, int y_offset, int x_offset);
int			deal_key(int key, t_data *data);
int			load_animations(t_data *data);
int			load_textures(t_data *data);
void		texture_map(t_data *data);
void		player_frame(t_data *data);
int			is_game_over(t_data *data);
int			end_game(t_data *data);
int			quit_game(t_data *data);
void		throw_error(t_error error);
void		free_map(t_data *data);
void		check_map(t_data *data);
void		check_lines_len(t_data *data);
t_map_check	initialize_counters(t_map_check counters);
void		check_borders_and_elements(t_data *data, t_map_check *counters);
void		check_elements(t_data *data, t_map_check *counters);
void		check_borders(t_data *data, t_map_check *counters);
void		check_file_extension(t_data *data, char *path);

#endif
