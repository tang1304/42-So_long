/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:03:39 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/07 17:04:18 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	change_anim(t_data *data, char c, int x, int y)
{
	if (c == 'C' && data->map.c_count == 1)
	{
		put_img(data, WALL_D, x, y);
	}
	else if (c == 'C' && data->map.c_count == 2)
	{
		put_img(data, COLLECTIBLE, x, y);
		data->map.c_count = 0;
	}
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
			if (data->map.map[y][x] == 'C')
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
	data->frames++;
	if (data->frames == 1000)
	{
		animate(data);
	}
	else if (data->frames == 2000)
	{
		animate(data);
	}
//	data->frames = 0;
	return (1);
}
