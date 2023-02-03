/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:49:15 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/02 20:06:11 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(t_data *data, int y, int x)
{
	if (data->map.map[data->map.p_y + y][data->map.p_x + x] == '1')
		return (0);
	else if (data->map.map[data->map.p_y + y][data->map.p_x + x] == 'C'
				&& data->map.c == 1)
		;
	else if (data->map.map[data->map.p_y + y][data->map.p_x + x] == 'E'
				&& data->map.c > 0)
		return (0);
	else if (data->map.map[data->map.p_y + y][data->map.p_x + x] == 'E'
				&& data->map.c == 0)
		;
}