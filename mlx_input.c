/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahidalg <rahidalg@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:08:53 by rahidalg          #+#    #+#             */
/*   Updated: 2024/12/25 11:08:55 by rahidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <errno.h>

void	clean_mlx(t_mlx_data *data)
{
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(1);
}

int	open_door(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (data->game.map[i].id != 'E')
	{
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->xpm_list.door_op.ptr, data->game.map[i].pos_x,
		data->game.map[i].pos_y);
	return (0);
}

int	move_player(int keysym, t_mlx_data *data)
{
	move_key(keysym, data);
	return (0);
}

char	*set_map_dir(int argc, char **argv)
{
	if (argc == 2)
	{
		return (argv[1]);
	}
	else
	{
		ft_printf("Error\nPass one directory for the map!!\n");
		exit(1);
	}
}

int	get_file(char *dir, t_mlx_data *data)
{
	int	fd;

	fd = open(dir, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nThe file can't be opened");
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	return (fd);
}
