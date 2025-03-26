/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahidalg <rahidalg@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:28:33 by rahidalg          #+#    #+#             */
/*   Updated: 2024/12/23 12:29:19 by rahidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_xpm_load(t_mlx_data *data)
{
	if (!save_xpm("sprites/world/wall.xpm", data, &data->xpm_list.wall))
		return (0);
	if (!save_xpm("sprites/world/floor.xpm", data, &data->xpm_list.floor))
		return (0);
	if (!save_xpm("sprites/obj/door_cd.xpm", data, &data->xpm_list.door_cd))
		return (0);
	if (!save_xpm("sprites/obj/door_opn.xpm", data, &data->xpm_list.door_op))
		return (0);
	if (!save_xpm("sprites/obj/coin.xpm", data, &data->xpm_list.coin))
		return (0);
	if (!save_xpm("sprites/ch/player.xpm", data, &data->xpm_list.player))
		return (0);
	if (!save_xpm("sprites/ch/p_exit.xpm", data, &data->xpm_list.exit_player))
		return (0);
	return (1);
}

int	load_mlx(t_mlx_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	return (1);
}

int	set_data(t_mlx_data *data)
{
	data->player_x = 0;
	data->player_y = 0;
	data->coins = 0;
	data->counter = 0;
	data->steps = 0;
	data->is_exit = 0;
	return (1);
}

int	set_window(t_mlx_data *data, char *dir)
{
	int	error;

	error = 0;
	data->game = load_map_size(dir, &error);
	check_size_error(error, data);
	if (!boundaries_checker(data, dir, data->game.win.width,
			data->game.win.height))
		return (0);
	valid_path(dir, data);
	data->game.win.width *= data->xpm_list.wall.width;
	data->game.win.height *= data->xpm_list.wall.height;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->game.win.width,
			data->game.win.height, "Maze Escape");
	if (data->win_ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (0);
	}
	data->game.map = load_map_data(dir, data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx_data		data;
	char			*dir;

	dir = set_map_dir(argc, argv);
	if (!check_extension(dir))
		return (1);
	set_data(&data);
	if (!load_mlx(&data))
		return (1);
	if (!chars_checker(dir, &data))
		clean_mlx(&data);
	if (!check_map_data(dir, &data))
		clean_mlx(&data);
	if (!mlx_xpm_load(&data))
		return (1);
	if (!set_window(&data, dir))
		return (1);
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_hook(data.win_ptr, 17, 0, press_red_cross, &data);
	mlx_loop(data.mlx_ptr);
	destroy_mlx(&data);
	return (0);
}
