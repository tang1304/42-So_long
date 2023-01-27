/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:54:12 by tgellon           #+#    #+#             */
/*   Updated: 2023/01/27 15:19:27 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + ((y * data->img.line_length) + (x * (data->img.bpp / 8)));
	*(unsigned int *)dst = color;
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
//	exit(EXIT_SUCCESS);
	return (0);
}

static void	data_init(t_data *data)
{
	data->map.c = 0;
	data->map.e = 0;
	data->map.p = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;
	// (void)argc;
	// (void)argv;

	// data.mlx = mlx_init();
	data_init(&data);
	map_init(&data, argc, argv);
	if (!&map_init)
		return (0);
	// int *leaks = malloc(100000);
	// (void) leaks;
	// data.win = mlx_new_window(data.mlx, 1280, 720, "So_long");
	// put_background(&data);
	// put_square(&data);
	// put_object(&data);
	// mlx_hook(data.win, 2, 1L << 0, ft_keyhook, &data);
	// mlx_loop(data.mlx);
	return (0);
}
