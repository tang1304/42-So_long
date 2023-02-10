/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:12:23 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/10 08:25:54 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* converts the xpm sprite to image and puts it on the window */
int	put_img(t_data *data, char *path, int x, int y)//TODO: fonction d'ouverture d'images, a stocker en struct de void*
{
	int	pxl;

	pxl = 64;
	x *= pxl;
	y *= pxl;
	data->img.img = mlx_xpm_file_to_image(data->mlx, path, &data->img.width,
			&data->img.height);
	if (!data->img.img)
	{
		printf("Error\nProblem loading xpm file\n");
		return (0);//TODO: check retour;
	}	
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, x, y);
	mlx_destroy_image(data->mlx, data->img.img);
	return (1);
}

/* Puts the floor sprite everywhere */
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

int	put_walls(t_data *data, int x, int y)
{
	int	tmp;

	if (x == 0 && y == 0)
		tmp = put_img(data, WALL_UL, x, y);
	else if (x == data->map.width - 1 && y == 0)
		tmp = put_img(data, WALL_UR, x, y);
	else if (x == 0 && y == data->map.height - 1)
		tmp = put_img(data, WALL_DL, x, y);
	else if (x == data->map.width - 1 && y == data->map.height - 1)
		tmp = put_img(data, WALL_DR, x, y);
	else if (x == 0 && y != data->map.height - 1 && y != 0)
		tmp = put_img(data, WALL_L, x, y);
	else if (x == data->map.width - 1 && y != data->map.height - 1 && y != 0)
		tmp = put_img(data, WALL_R, x, y);
	else if (x != data->map.width - 1 && x != 0 && y == 0)
		tmp = put_img(data, WALL_U, x, y);
	else if (x != data->map.width - 1 && x != 0 && y == data->map.height - 1)
		tmp = put_img(data, WALL_D, x, y);
	if (tmp == 0)
		return (0);
	return (1);
}

/* selects the good sprite depending on the char */
int	choose_img(t_data *data, char c, int x, int y)
{
	int	tmp;

	if (c == '1' && (x == 0 || x == data->map.width - 1 || y == 0
			|| y == data->map.height - 1))
		tmp = put_walls(data, x, y);
	else if (c == '1')
		tmp = put_img(data, OBSTACLE, x, y);
	else if (c == 'C')
		tmp = put_img(data, COLLECTIBLE, x, y);
	else if (c == 'P')
		tmp = put_img(data, P_FRONT_STILL, x, y);
	else if (c == 'E')
	{
		tmp = put_img(data, EXIT_OFF, x, y);
		data->map.e_x = x;
		data->map.e_y = y;
	}
	else if (c == 'D')
	{
		tmp = put_img(data, D_STILL, x, y);
		data->d_nbr++;
	}
	if (tmp == 0)
		return (0);
	return (1);
}

/* main function to display the game */
int	put_map(t_data *data)
{
	int	x;
	int	y;

	if (!put_background(data))
		return (0);
	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (!choose_img(data, data->map.map[y][x], x, y))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
