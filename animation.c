/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:03:39 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/08 18:29:45 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	change_anim(t_data *data, char c, int x, int y)
{
	int	d;

	d = data->d_nbr;
	if (c == 'D' && data->map.c_count <= d)
		put_img(data, D_LEFT, x, y);
	else if (c == 'D' && data->map.c_count <= d * 2)
		put_img(data, D_STILL, x, y);
	else if (c == 'D' && data->map.c_count <= d * 3)
		put_img(data, D_RIGHT, x, y);
	else if (c == 'D' && data->map.c_count <= d * 4)
		put_img(data, D_STILL, x, y);
	if (data->map.c_count == d * 4)
		data->map.c_count = 0;
	data->map.c_count++;
	return (1);
}

static int	animate(t_data *data)
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
				if (!change_anim(data, data->map.map[y][x], x, y))
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
	animate(data);
	return (1);
}
