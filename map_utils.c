/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahidalg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:30:16 by rahidalg          #+#    #+#             */
/*   Updated: 2024/12/27 13:08:38 by rahidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_next_line(int fd, char *line)
{
	free(line);
	return (get_next_line(fd));
}

int	chars_checker(char *dir, t_mlx_data *data)
{
	char	*line;
	int		i;
	int		ch_error;
	int		fd;

	i = 0;
	ch_error = 1;
	fd = get_file(dir, data);
	line = get_next_line(fd);
	while (line != NULL)
	{
		while (line[i] != '\n' && line[i] != '\0')
		{
			if (ch_error && (line[i] != '0' && line[i] != '1' && line[i] != 'C'
					&& line[i] != 'E' && line[i] != 'P'))
				ch_error = 0;
			i++;
		}
		i = 0;
		line = read_next_line(fd, line);
	}
	if (!ch_error)
		ft_printf("Error\nThe map have unknown characters!\n");
	return (ch_error);
}

int	map_checker(int fd, int player_count, int coin_count, int door_count)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		while (line[i] != '\n' && line[i] != '\0')
		{
			i++;
			if (line[i] == 'P')
				player_count += 1;
			else if (line[i] == 'C')
				coin_count += 1;
			else if (line[i] == 'E')
				door_count += 1;
		}
		i = 0;
		line = read_next_line(fd, line);
	}
	if (!map_handler(player_count, coin_count, door_count))
		return (0);
	return (1);
}

int	map_position(t_map_data *map, char id, int pos_x, int pos_y)
{
	map->id = id;
	map->pos_x = pos_x;
	map->pos_y = pos_y;
	return (1);
}

void	check_size_error(int error, t_mlx_data *data)
{
	if (error == 1)
	{
		ft_printf("Error\nThe map is not rectangular!\n");
		close_mlx(data);
		exit (1);
	}
}
