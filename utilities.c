/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahidalg <rahidalg@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:01:57 by rahidalg          #+#    #+#             */
/*   Updated: 2024/12/25 11:02:04 by rahidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_images(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->xpm_list.wall.ptr);
	mlx_destroy_image(data->mlx_ptr, data->xpm_list.floor.ptr);
	mlx_destroy_image(data->mlx_ptr, data->xpm_list.door_cd.ptr);
	mlx_destroy_image(data->mlx_ptr, data->xpm_list.door_op.ptr);
	mlx_destroy_image(data->mlx_ptr, data->xpm_list.coin.ptr);
	mlx_destroy_image(data->mlx_ptr, data->xpm_list.player.ptr);
	mlx_destroy_image(data->mlx_ptr, data->xpm_list.exit_player.ptr);
	return (0);
}

int	destroy_mlx(t_mlx_data *data)
{
	free_images(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->game.map);
	return (0);
}

int	press_red_cross(t_mlx_data *data)
{
	ft_printf("Red cross pressed, closing window...\n");
	destroy_mlx(data);
	exit(1);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("ESC key pressed, closing window...\n");
		destroy_mlx(data);
		exit(1);
	}
	move_player(keysym, data);
	return (0);
}

void	set_initial_value(int *i, int *x, int *y, int *d)
{
	*i = 0;
	*x = 0;
	*y = 0;
	*d = 0;
}
