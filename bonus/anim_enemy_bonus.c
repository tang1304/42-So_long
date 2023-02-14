/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:03:39 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/10 16:57:35 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	change_anim_enemy(t_data *data, char c, int x, int y)
{
	int	tmp;

	if (c == 'D' && data->map.c_count <= data->d_nbr)
		tmp = put_img(data, D_LEFT, x, y);
	else if (c == 'D' && data->map.c_count <= data->d_nbr * 2)
		tmp = put_img(data, D_STILL, x, y);
	else if (c == 'D' && data->map.c_count <= data->d_nbr * 3)
		tmp = put_img(data, D_RIGHT, x, y);
	else if (c == 'D' && data->map.c_count <= data->d_nbr * 4)
		tmp = put_img(data, D_STILL, x, y);
	if (tmp == 0)
		return (0);
	if (data->map.c_count == data->d_nbr * 4)
		data->map.c_count = 0;
	data->map.c_count++;
	return (1);
}

static int	animate_enemy(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'D')
			{
				if (!change_anim_enemy(data, data->map.map[y][x], x, y))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	frame_rendering(t_data *data)
{
	if (data->frames < ANIMATION)
	{
		data->frames++;
		return (0);
	}
	else
		data->frames = 0;
	animate_enemy(data);
	return (1);
}
