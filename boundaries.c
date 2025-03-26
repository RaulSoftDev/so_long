/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundaries.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahidalg <rahidalg@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:53:55 by rahidalg          #+#    #+#             */
/*   Updated: 2025/01/18 08:40:28 by rahidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_mlx(t_mlx_data *data)
{
	free_images(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	boundaries_checker(t_mlx_data *data, char *dir, int size_x, int size_y)
{
	int		fd;
	char	*line;

	fd = open(dir, O_RDONLY);
	line = get_next_line(fd);
	if (!get_boundaries(fd, line, size_x, size_y))
	{
		close_mlx(data);
		ft_printf("Error\nThe boundaries are open!\n");
		return (0);
	}
	close(fd);
	return (1);
}

void	check_full_line(char *line, int *error)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1')
			*error = 1;
		i++;
	}
	i = 0;
}

int	get_boundaries(int fd, char *line, int size_x, int size_y)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (line != NULL)
	{
		if (i == 0 || i == size_y - 1)
		{
			check_full_line(line, &error);
		}
		else
		{
			if (line[0] != '1' || line[size_x - 1] != '1')
				error = 1;
		}
		i++;
		line = read_next_line(fd, line);
	}
	if (error == 1)
		return (0);
	return (1);
}
