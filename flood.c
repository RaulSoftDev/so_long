/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahidalg <rahidalg@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:30:32 by rahidalg          #+#    #+#             */
/*   Updated: 2025/01/23 10:30:51 by rahidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_map_rows(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j] && map[i][j] != '\n')
		{
			j++;
		}
		map[i][j] = '\0';
		j = 0;
		i++;
	}
}

void	get_player(char **map, t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
			}
			else if (map[i][j] == 'C')
				data->coins++;
			j++;
		}
		j = 0;
		i++;
	}
}

void	debbug_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		j = 0;
		i++;
	}
}

int	boundary_fill(t_mlx_data *data, char **map, int x, int y)
{
	int	up;
	int	down;
	int	right;
	int	left;

	if (y < 0 || y >= data->game.win.height || x < 0
		|| x >= data->game.win.width || map[y][x] == '1')
		return (0);
	if (map[y][x] == 'C')
		data->counter++;
	if (map[y][x] == 'E')
		data->is_exit++;
	map[y][x] = '1';
	up = boundary_fill(data, map, x, y - 1);
	down = boundary_fill(data, map, x, y + 1);
	right = boundary_fill(data, map, x + 1, y);
	left = boundary_fill(data, map, x - 1, y);
	if (up || down || left || right)
		return (1);
	else
		return (0);
}

void	read_map(int fd, char **map, t_mlx_data *data)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (i < data->game.win.height)
	{
		alloc_map(map, line, i);
		ft_strlcpy(map[i], line, (ft_strlen(line) + 1));
		line = read_next_line(fd, line);
		i++;
	}
	map[i] = NULL;
	close_map_rows(map);
	get_player(map, data);
	boundary_fill(data, map, data->player_x, data->player_y);
}
