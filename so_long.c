/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:54:12 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/03 16:03:06 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_map_error(t_data *data)
{
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_FAILURE);
}

int	ft_close_win_error(t_data *data)
{
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_maps(data);
	exit(EXIT_FAILURE);
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_maps(data);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_printf("Error\nMlx error\n"), 0);
	data_init(&data);
	if (!map_init(&data, argc, argv))
		ft_close_map_error(&data);
	data.win = mlx_new_window(data.mlx, (data.map.width * 64), \
			(data.map.height * 64), "So_long");
	if (!data.win)
		ft_close_win_error(&data);
	if (!put_map(&data))
		ft_close(&data);
	mlx_key_hook(data.win, keyhook, &data);
	mlx_hook(data.win, 17, 0, ft_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
