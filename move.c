/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:49:15 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/14 15:27:01 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Puts the character sprite depending on the key pressed */
static int	direction(t_data *data, int keycode)
{
	int	tmp;

	if (keycode == W)
		tmp = put_img(data, P_BACK_STILL, data->map.p_x, data->map.p_y);
	else if (keycode == S)
		tmp = put_img(data, P_FRONT_STILL, data->map.p_x, data->map.p_y);
	else if (keycode == A)
		tmp = put_img(data, P_LEFT_STILL, data->map.p_x, data->map.p_y);
	else if (keycode == D)
		tmp = put_img(data, P_RIGHT_STILL, data->map.p_x, data->map.p_y);
	if (tmp == 0)
		return (0);
	return (1);
}

static int	move_2(t_data *data, int y, int x)
{
	if (data->map.map[data->map.p_y + y][data->map.p_x + x] == '1')
		return (0);
	else if (data->map.map[data->map.p_y + y][data->map.p_x + x] == 'C'
				&& data->c_nbr >= 1)
	{
		data->c_nbr--;
		data->map.map[data->map.p_y + y][data->map.p_x + x] = '0';
	}
	else if (data->map.map[data->map.p_y + y][data->map.p_x + x] == 'E'
				&& data->c_nbr > 0)
		return (ft_printf("Get all the beers first !\n"), 0);
	return (1);
}

/* function done when a key is pressed */
int	move(t_data *data, int y, int x, int keycode)
{
	if (!direction(data, keycode))
		return (0);
	if (!move_2(data, y, x))
		return (2);
	if (!put_img(data, FLOOR, data->map.p_x, data->map.p_y))
		return (0);
	if (data->c_nbr == 0)
	{
		if (!put_img(data, EXIT_ON, data->map.e_x, data->map.e_y))
			return (0);
	}
	data->map.p_x += x;
	data->map.p_y += y;
	data->moves++;
	ft_printf("Your moves : %d\n", data->moves);
	if (!direction(data, keycode))
		return (0);
	return (1);
}
