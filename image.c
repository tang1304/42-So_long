/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:12:23 by tgellon           #+#    #+#             */
/*   Updated: 2023/01/26 14:35:48 by tgellon          ###   ########lyon.fr   */
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
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 500, 300);
}

void	put_object(t_data *data)
{
	data->img.img = mlx_xpm_file_to_image(data->mlx, "./sprites/table.xpm", &data->img.height, &data->img.width);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 400, 300);
}

void	put_background(t_data *data)
{
	int		x;
	int		y;
	float	color;
	float	color_min;
	float	color_max;
	float	delta_color;

	color_min = 0x0000FF;
	color_max = 0x00FF00;
	delta_color = ((color_max - color_min) / 1280);
	color = color_max;
	x = 0;
	data->img.img = mlx_new_image(data->mlx, 1280, 720);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_length, &data->img.endian);
	while (x < 1280)
	{
		y = 0;
		while (y < 720)
		{
			my_mlx_pixel_put(data, x, y, (int)color);
			y++;
		}
		color -= delta_color;
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
