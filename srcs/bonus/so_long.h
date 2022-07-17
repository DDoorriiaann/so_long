/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dguet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:52:42 by dguet             #+#    #+#             */
/*   Updated: 2022/07/05 17:53:28 by dguet            ###   ########.fr       */
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
	void		*moves_frame;
	void		*wall;
	void		*exit[3];
	int			exit_coord[2];
	int			exit_status;
	int			player_dir;
	void		*p_anim_r[5];
	void		*p_anim_l[5];
	void		*p_anim_s[6];
	int			player_h;
	int			player_w;
	void		*collectible_anim[1];
	int			collectibles_nb;
	int			collectibles_h[100];
	int			collectibles_w[100];
}	t_game;

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
}	t_data;

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

static const t_errordesc	g_errordesc[9] = {
{NO_ERROR, "No error"},
{CORRUPTED_FILE, "The map file is corrupted or missing"},
{WRONG_LINE_LENGTH, "Line length is inconsistent"},
{MALLOC_ERROR, "Malloc failed to allocate memory"},
{MAP_TOO_SMALL, "The map is too small"},
{MAP_BORDER_ERROR, "The map border is inconsistent"},
{UNKNOWN_MAP_ELEMENT, "The map contains an element from an unknown type"},
{WRONG_FILE_EXTENSION, "Wrong file extension"},
{INVALID_MAP, "Invalid map"},
};

t_error	parse_map(char *filename, t_data *data);
void	move_player(t_data *data, int x_offset, int y_offset);
void	move_player_up(t_data *data);
void	move_player_down(t_data *data);
void	move_player_left(t_data *data);
void	move_player_right(t_data *data);
void	put_exit(int w, int h, t_data *data);
void	put_background(int w, int h, t_data *data);
void	put_wall(int w, int h, t_data *data);
void	put_collectible(int w, int h, t_data *data);
void	put_player(int w, int h, t_data *data);
int		update_exit(t_data *data, int code);
int		put_moves_counter_frame(t_data *data);
int		update_moves_counter(t_data *data);
int		put_collectibles_counter_frame(t_data *data);
int		update_collectibles_counter(t_data *data);
int		remove_collectible(t_data *data, int y_offset, int x_offset);
int		clock(t_data *data);
int		ft_rand(void);
int		deal_key(int key, t_data *data);
int		load_animations(t_data *data);
int		load_textures(t_data *data);
void	texture_map(t_data *data);
void	player_frame(t_data *data);
int		is_game_over(t_data *data);
int		end_game(t_data *data);
void	destroy_images(t_data *data);
void	destroy_game(t_data *data);
int		quit_game(t_data *data);
void	throw_error(t_error error);
t_error	check_map(t_data *data);
t_error	check_file_extension(char *path);

#endif
