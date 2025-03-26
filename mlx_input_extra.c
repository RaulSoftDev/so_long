/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahidalg <rahidalg@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 11:17:16 by rahidalg          #+#    #+#             */
/*   Updated: 2024/12/27 12:28:31 by rahidalg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *dir)
{
	char	*check;
	char	*ref;

	ref = ".ber";
	check = ft_substr((char const *)dir, ft_strlen(dir) - 4, ft_strlen(dir));
	if (ft_strncmp((const char *)ref, (const char *)check, ft_strlen(dir)) != 0)
	{
		ft_printf("The map extension is not .ber!\n");
		free(check);
		return (0);
	}
	free(check);
	return (1);
}

int	save_dir(t_mlx_data *data, int keysym)
{
	if (keysym == XK_w)
	{
		data->pre_y -= data->xpm_list.player.height;
	}
	else if (keysym == XK_s)
	{
		data->pre_y += data->xpm_list.player.height;
	}
	else if (keysym == XK_a)
	{
		data->pre_x -= data->xpm_list.player.width;
	}
	else if (keysym == XK_d)
	{
		data->pre_x += data->xpm_list.player.width;
	}
	return (1);
}

int	check_counter(char id, t_mlx_data *data)
{
	if (id == 'C')
	{
		data->counter += 1;
		ft_printf("Coins: %d/%d\n", data->counter, data->coins);
		check_coins(data);
	}
	return (0);
}

int	check_end(char id, t_mlx_data *data)
{
	if (id == 'E' && data->counter == data->coins)
	{
		ft_printf("YOU HAVE ESCAPED THE MAZE!!\n");
		destroy_mlx(data);
		exit(1);
	}
	return (0);
}

int	move_key(int keysym, t_mlx_data *data)
{
	char	id;

	data->pre_x = data->player_x;
	data->pre_y = data->player_y;
	if (keysym == XK_w || keysym == XK_s || keysym == XK_a || keysym == XK_d)
	{
		save_dir(data, keysym);
		id = check_movement(data, data->pre_x, data->pre_y);
		if (id == '0' || id == 'P' || id == 'C')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->xpm_list.wall.ptr, data->player_x, data->player_y);
			data->player_x = data->pre_x;
			data->player_y = data->pre_y;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->xpm_list.player.ptr, data->player_x, data->player_y);
			data->steps += 1;
			ft_printf("Steps: %d\n", data->steps);
			check_counter(id, data);
		}
		else
			check_end(id, data);
	}
	return (0);
}
