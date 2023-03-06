/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:31:57 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/06 09:07:25 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	choose_enemy_img(t_data *data, int x, int y)
{
	int	tmp;

	tmp = put_img(data, D_STILL, x, y);
	data->d_nbr++;
	return (tmp);
}

/* selects the good sprite depending on the char */
int	choose_img(t_data *data, char c, int x, int y)
{
	int	tmp;

	tmp = 1;
	if (c == '1' && (x == 0 || x == data->map.width - 1 || y == 0 \
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
		tmp = choose_enemy_img(data, x, y);
	if (tmp == 0)
		return (0);
	return (1);
}
