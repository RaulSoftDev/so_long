/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahidalg <rahidalg@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:20:42 by rahidalg          #+#    #+#             */
/*   Updated: 2024/12/17 13:23:27 by rahidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "X11/keysym.h"
# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_window
{
	int	width;
	int	height;
}			t_window;

typedef struct s_xpm
{
	void	*ptr;
	int		width;
	int		height;
}				t_xpm;

typedef struct s_xpm_list
{
	t_xpm	wall;
	t_xpm	floor;
	t_xpm	door_cd;
	t_xpm	door_op;
	t_xpm	coin;
	t_xpm	player;
	t_xpm	exit_player;
}				t_xpm_list;

typedef struct s_map_data
{
	int		pos_x;
	int		pos_y;
	char	id;
}				t_map_data;

typedef struct s_game_data
{
	t_window	win;
	t_map_data	*map;
}					t_game_data;

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_xpm_list		xpm_list;
	t_game_data		game;
	int				player_x;
	int				player_y;
	int				pre_x;
	int				pre_y;
	int				coins;
	int				counter;
	int				steps;
	int				is_exit;
}						t_mlx_data;

//FUNCTIONS
t_game_data	load_map_size(char *map_directory, int *error);
int			check_map_data(char	*map_directory, t_mlx_data *data);
t_map_data	*load_map_data(char *map_directory, t_mlx_data *mlx);
int			move_key(int keysym, t_mlx_data *data);
int			open_door(t_mlx_data *data);
int			move_player(int keysym, t_mlx_data *data);
char		*set_map_dir(int argc, char **argv);
int			get_file(char *dir, t_mlx_data *data);
int			check_extension(char *dir);
//CHECKS
char		check_movement(t_mlx_data *data, int pos_x, int pos_y);
int			check_coins(t_mlx_data *data);
int			save_xpm(char *directory, t_mlx_data *data, t_xpm *xpm);
int			chars_checker(char *dir, t_mlx_data *data);
int			map_handler(int player_count, int coin_count, int door_count);
void		check_map_size(int *x, int *map_width, int *error);
//BOUNDARIES
int			boundaries_checker(t_mlx_data *data, char *dir,
				int size_x, int size_y);
int			get_boundaries(int fd, char *line, int size_x, int size_y);
//PATH
void		alloc_map(char **map, char *line, int row);
void		valid_path(char *dir, t_mlx_data *data);
//FLOOD
void		read_map(int fd, char **map, t_mlx_data *data);
//UTILITIES
int			free_images(t_mlx_data *data);
int			destroy_mlx(t_mlx_data *data);
int			press_red_cross(t_mlx_data *data);
int			handle_input(int keysym, t_mlx_data *data);
void		set_initial_value(int *i, int *x, int *y, int *d);
int			set_data(t_mlx_data *data);
//MAP UTILS
char		*read_next_line(int fd, char *line);
int			map_checker(int fd, int player_count,
				int coin_count, int door_count);
int			map_position(t_map_data *map, char id, int pos_x, int pos_y);
void		check_size_error(int error, t_mlx_data *data);
//MLX
void		clean_mlx(t_mlx_data *data);
void		close_mlx(t_mlx_data *data);

#endif //SO_LONG_H
