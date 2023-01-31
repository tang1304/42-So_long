/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:12:23 by tgellon           #+#    #+#             */
/*   Updated: 2023/01/31 18:21:26 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_square(t_data *data)
{
	int		x;
	int		y;
	int		color;

	x = 0;
	data->img.height = 50;
	data->img.width = 50;
	data->img.img = mlx_new_image(data->mlx, data->img.height, data->img.width);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_length, &data->img.endian);
	while (x < data->img.width)
	{
		y = 0;
		while (y < data->img.height)
		{
			if (x == 0 || x == data->img.width - 1 || y == 0 || y == data->img.height - 1)
				color = 0x00000000;
			else
				color = 0x00FFFF00;
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 150, 50);
}

void	put_background(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	data->img.img = mlx_new_image(data->mlx, 1280, 720); //TODO: a proteger
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

int	put_img(t_data *data, char *path, int x, int y)
{
	data->img.img = mlx_xpm_file_to_image(data->mlx, path, x * 64, y * 64);
	if (!data->img.img)
		return (0);//TODO: check retour;
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, x, y);
}

int	choose_img(t_data *data, char c, int x, int y)
{
	if (c == '1' && (x == 0 || x == data->map.width || y == 0
			|| y == data->map.height))
		put_img(data, WALL, x, y);
	else if (c == '1')
		put_img(data, OBSTACLE, x, y);
	else if (c == 'C')
		put_img(data, COLLECTIBLE, x, y);
	else if (c == 'P')
		put_img(data, PLAYER, x, y);
	else if (c == 'E')
		put_img(data, EXIT, x, y);
	return (1);
}

int	put_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	put_background(data);
	while (data->map.map[y])
	{
		while (data->map.map[y][x])
		{
			choose_img(data, data->map.map[y][x], x, y);
		}
	}
}
