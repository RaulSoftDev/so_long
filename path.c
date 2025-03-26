/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahidalg <rahidalg@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:55:36 by rahidalg          #+#    #+#             */
/*   Updated: 2025/01/18 12:55:54 by rahidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	alloc_map(char **map, char *line, int row)
{
	map[row] = malloc((ft_strlen(line) + 1) * sizeof(char));
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	valid_path(char *dir, t_mlx_data *data)
{
	int		fd;
	char	**map;

	fd = open(dir, O_RDONLY);
	map = malloc((data->game.win.height + 1) * sizeof(char *));
	read_map(fd, map, data);
	close(fd);
	free_map(map);
	if (data->counter != data->coins || data->is_exit != 1)
	{
		ft_printf("Error\nThe map cannot be completed!\n");
		close_mlx(data);
		exit(1);
	}
	set_data(data);
}
