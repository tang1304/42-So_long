/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:54:12 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/07 12:24:33 by tgellon          ###   ########lyon.fr   */
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
	data->moves = 0;
	data->frames = 0;
	data->map.c_count = 0;
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
	if (!data.win)
		return (ft_free_maps(&data), 0);
	if (!put_map(&data))
	{
		ft_free_maps(&data);
		mlx_destroy_window(data.mlx, data.win);
		return (0);//TODO: remplacer par exit
	}
	mlx_hook(data.win, 2, 1L << 0, keyhook, &data);
	mlx_hook(data.win, 17, 0, ft_close, &data);
	mlx_string_put(data.mlx, data.win, 20, 20, 0x00E11B, "Moves : 0");
	mlx_loop_hook(data.mlx, frame_rendering, &data);
	mlx_loop(data.mlx);
	ft_free_maps(&data);
	return (0);
}
