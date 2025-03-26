/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahidalg <rahidalg@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:09:22 by rahidalg          #+#    #+#             */
/*   Updated: 2024/12/25 11:09:24 by rahidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	check_movement(t_mlx_data *data, int pos_x, int pos_y)
{
	int		i;
	char	id;

	i = 0;
	while (data->game.map[i].id != '\0')
	{
		if (data->game.map[i].pos_x == pos_x)
		{
			if (data->game.map[i].pos_y == pos_y)
			{
				id = data->game.map[i].id;
				if (id == 'C')
					data->game.map[i].id = '0';
				return (id);
			}
		}
		i++;
	}
	return ('\0');
}

int	check_coins(t_mlx_data *data)
{
	if (data->counter == data->coins)
		open_door(data);
	return (0);
}

int	map_handler(int player_count, int coin_count, int door_count)
{
	if (player_count <= 0 || player_count > 1)
	{
		ft_printf("Error\nThe map must have one player instance!\n");
		return (0);
	}
	else if (coin_count <= 0)
	{
		ft_printf("Error\nThe map must have at least one coin!\n");
		return (0);
	}
	else if (door_count <= 0 || door_count > 1)
	{
		ft_printf("Error\nThe map must have one exit door instance!\n");
		return (0);
	}
	return (1);
}

void	check_map_size(int *x, int *map_width, int *error)
{
	int	zero;

	zero = 0;
	if (*map_width == 0)
	{
		*map_width = *x;
	}
	else if (*x != *map_width)
	{
		*error = 1;
	}
	*x = zero;
}

int	save_xpm(char *directory, t_mlx_data *data, t_xpm *xpm)
{
	xpm->ptr = mlx_xpm_file_to_image(data->mlx_ptr,
			directory, &xpm->width, &xpm->height);
	if (xpm->ptr == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (0);
	}
	return (1);
}
