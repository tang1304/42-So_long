/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:26:21 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/03 12:07:56 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhook(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		ft_printf("ESC pressed\n");
		ft_close(data);
	}
	else if (keycode == W)
	{
		move(data, -1, 0, W);
	}
	else if (keycode == A)
	{
		move(data, 0, -1, A);
	}
	else if (keycode == S)
	{
		move(data, 1, 0, S);
	}
	else if (keycode == D)
	{
		move(data, 0, 1, D);
	}
	if (data->map.map[data->map.p_y][data->map.p_x] == 'E' && data->c_nbr == 0)
		ft_close(data);
	return (0);
}
