/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:12:23 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/02 20:03:06 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_img(t_data *data, char *path, int x, int y)
{
	int	pxl;

	pxl = 64;
	x *= pxl;
	y *= pxl;
	data->img.img = mlx_xpm_file_to_image(data->mlx, path, &data->img.width,
			&data->img.height);
	if (!data->img.img)
		return (0);//TODO: check retour;
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, x, y);
	mlx_destroy_image(data->mlx, data->img.img);
	return (1);
}

int	put_background(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (!put_img(data, FLOOR, x, y))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	choose_img(t_data *data, char c, int x, int y)
{
	if (c == '1' && (x == 0 || x == data->map.width - 1 || y == 0
			|| y == data->map.height - 1))
		put_img(data, WALL, x, y);
	else if (c == '1')
		put_img(data, OBSTACLE, x, y);
	else if (c == 'C')
		put_img(data, COLLECTIBLE, x, y);
	else if (c == 'P')
		put_img(data, PLAYER, x, y);
	else if (c == 'E')
		put_img(data, EXIT_OFF, x, y);
	return (1);
}

int	put_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			choose_img(data, data->map.map[y][x], x, y);
			x++;
		}
		y++;
	}
	return (1);
}
