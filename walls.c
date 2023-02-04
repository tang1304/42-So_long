/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:31:41 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/04 12:49:40 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	sub_put_walls(t_data *data, int x, int y)
{
	if (x == 0 && y != data->map.height - 1 && y != 0)
	{
		if (!put_img(data, WALL_L, x, y))
			return (0);
	}
	else if (x == data->map.width - 1 && y != data->map.height - 1 && y != 0)
	{
		if (!put_img(data, WALL_R, x, y))
			return (0);
	}
	else if (x != data->map.width - 1 && x != 0 && y == 0)
	{
		if (!put_img(data, WALL_U, x, y))
			return (0);
	}
	else if (x != data->map.width - 1 && x != 0 && y == data->map.height - 1)
	{
		if (!put_img(data, WALL_D, x, y))
			return (0);
	}
	return (1);
}

int	put_walls(t_data *data, int x, int y)
{
	if (x == 0 && y == 0)
	{
		if (!put_img(data, WALL_UL, x, y))
			return (0);
	}
	else if (x == data->map.width - 1 && y == 0)
	{
		if (!put_img(data, WALL_UR, x, y))
			return (0);
	}
	else if (x == 0 && y == data->map.height - 1)
	{
		if (!put_img(data, WALL_DL, x, y))
			return (0);
	}
	else if (x == data->map.width - 1 && y == data->map.height - 1)
	{
		if (!put_img(data, WALL_DR, x, y))
			return (0);
	}
	else
	{
		if (!sub_put_walls(data, x, y))
			return (0);
	}
	return (1);
}
