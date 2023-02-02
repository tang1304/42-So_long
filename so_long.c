/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:54:12 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/02 20:03:27 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
}

static void	data_init(t_data *data)
{
	data->map.c = 0;
	data->map.e = 0;
	data->map.p = 0;
}

int	main(int argc, char **argv)//TODO: securiser fonction mlx renvoyant un void*
{
	t_data	data;

	data.mlx = mlx_init();
	if (!mlx_init())
		return (ft_printf("Error\nMlx error\n"), 0);
	data_init(&data);
	if (!map_init(&data, argc, argv))
		return (0);
	data.win = mlx_new_window(data.mlx, (data.map.width * 64),
			(data.map.height * 64), "So_long");
	put_background(&data);
	put_map(&data);
	mlx_hook(data.win, 2, 1L << 0, keyhook, &data);
	mlx_hook(data.win, 17, 0, ft_close, &data);
	mlx_loop(data.mlx);
	ft_free_maps(&data);
	return (0);
}
