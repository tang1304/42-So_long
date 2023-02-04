/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:26:21 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/04 12:10:42 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhook(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_close(data);
	else if (keycode == W)
	{
		if (!move(data, -1, 0, W))
			return (0);
	}
	else if (keycode == A)
	{
		if (!move(data, 0, -1, A))
			return (0);
	}
	else if (keycode == S)
	{
		if (!move(data, 1, 0, S))
			return (0);
	}
	else if (keycode == D)
	{
		if (!move(data, 0, 1, D))
			return (0);
	}
	if (data->map.map[data->map.p_y][data->map.p_x] == 'E' && data->c_nbr == 0)
		ft_close(data);
	return (0);
}
