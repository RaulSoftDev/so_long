/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahidalg <rahidalg@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:06:07 by rahidalg          #+#    #+#             */
/*   Updated: 2025/01/07 14:44:59 by rahidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game_data	load_map_size(char *map_directory, int *error)
{
	int			i;
	int			j;
	int			fd;
	char		*map_info;
	t_game_data	data;

	i = 0;
	j = 0;
	data.win.width = 0;
	fd = open(map_directory, O_RDONLY);
	map_info = get_next_line(fd);
	while (map_info != NULL)
	{
		while (map_info[i] != '\n' && map_info[i] != '\0')
		{
			i++;
		}
		free(map_info);
		check_map_size(&i, &data.win.width, error);
		j++;
		map_info = get_next_line(fd);
	}
	data.win.height = j;
	close(fd);
	return (data);
}

int	check_map_data(char	*map_directory, t_mlx_data *data)
{
	int	fd;
	int	player_count;
	int	coin_count;
	int	door_count;

	player_count = 0;
	coin_count = 0;
	door_count = 0;
	fd = get_file(map_directory, data);
	if (!map_checker(fd, player_count, coin_count, door_count))
		return (0);
	close(fd);
	return (1);
}

void	*set_image(t_mlx_data *mlx, char map_line, int pos_x, int pos_y)
{
	if (map_line == '1')
	{
		return (mlx->xpm_list.floor.ptr);
	}
	else if (map_line == '0')
	{
		return (mlx->xpm_list.wall.ptr);
	}
	else if (map_line == 'E')
	{
		return (mlx->xpm_list.door_cd.ptr);
	}
	else if (map_line == 'C')
	{
		mlx->coins += 1;
		return (mlx->xpm_list.coin.ptr);
	}
	else if (map_line == 'P')
	{
		mlx->player_x = pos_x;
		mlx->player_y = pos_y;
		return (mlx->xpm_list.player.ptr);
	}
	return ((void *) NULL);
}

void	show_map(t_mlx_data *mlx, char *map_line, t_map_data *map, int fd)
{
	int	i;
	int	x;
	int	y;
	int	d;

	set_initial_value(&i, &x, &y, &d);
	map_line = get_next_line(fd);
	while (map_line != NULL)
	{
		while (map_line[i] != '\n' && map_line[i] != '\0')
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				set_image(mlx, map_line[i], x, y), x, y);
			map_position(&map[d], map_line[i], x, y);
			x += mlx->xpm_list.floor.width;
			d++;
			i++;
		}
		x = 0;
		y += mlx->xpm_list.floor.height;
		i = 0;
		map_line = read_next_line(fd, map_line);
	}
	map[d].id = '\0';
}

t_map_data	*load_map_data(char *map_directory, t_mlx_data *mlx)
{
	int			fd;
	char		*map_line;
	t_map_data	*map;

	map_line = NULL;
	fd = open(map_directory, O_RDONLY);
	map = malloc((mlx->game.win.width * mlx->game.win.height) * sizeof(*map));
	show_map(mlx, map_line, map, fd);
	close(fd);
	return (map);
}
