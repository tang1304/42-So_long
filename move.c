/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:49:15 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/03 11:26:36 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	direction(t_data *data, int keycode)
{
	if (keycode == W)
		put_img(data, P_BACK_STILL, data->map.p_x, data->map.p_y);
	else if (keycode == S)
		put_img(data, P_FRONT_STILL, data->map.p_x, data->map.p_y);
	else if (keycode == A)
		put_img(data, P_LEFT_STILL, data->map.p_x, data->map.p_y);
	else if (keycode == D)
		put_img(data, P_RIGHT_STILL, data->map.p_x, data->map.p_y);
}

int	move(t_data *data, int y, int x, int keycode)
{
	direction(data, keycode);
	if (data->map.map[data->map.p_y + y][data->map.p_x + x] == '1')
		return (0);
	else if (data->map.map[data->map.p_y + y][data->map.p_x + x] == 'C'
				&& data->map.c == 1)
	{
		data->map.c--;
	}
	else if (data->map.map[data->map.p_y + y][data->map.p_x + x] == 'E'
				&& data->map.c > 0)
		return (0);
	put_img(data, FLOOR, data->map.p_x, data->map.p_y);
	data->map.p_x += x;
	data->map.p_y += y;
	direction(data, keycode);
	return (1);
}
