/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:26:21 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/10 16:56:37 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	keyhook(int keycode, t_data *data)
{
	int	tmp;

	if (keycode == ESC)
	{
		ft_printf("You gave up ! LLLLLLLLOSER !!!\n");
		ft_close(data);
	}
	else if (keycode == W)
		tmp = move(data, -1, 0, W);
	else if (keycode == A)
		tmp = move(data, 0, -1, A);
	else if (keycode == S)
		tmp = move(data, 1, 0, S);
	else if (keycode == D)
		tmp = move(data, 0, 1, D);
	if (tmp == 0)
		return (0);
	if (data->map.map[data->map.p_y][data->map.p_x] == 'E' && data->c_nbr == 0)
	{
		ft_printf("Congratulations, you win ! Cheers !\n");
		ft_close(data);
	}
	return (0);
}
