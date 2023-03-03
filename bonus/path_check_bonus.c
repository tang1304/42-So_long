/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:21:48 by tgellon           #+#    #+#             */
/*   Updated: 2023/03/03 16:05:40 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	recursive_call(t_data *data, int x, int y)
{
	if (data->mapcpy[y][x - 1] == '0' || data->mapcpy[y][x - 1] == 'C' \
		|| data->mapcpy[y][x - 1] == 'E')
		path_check(data, x - 1, y);
	if (data->mapcpy[y][x + 1] == '0' || data->mapcpy[y][x + 1] == 'C' \
		|| data->mapcpy[y][x + 1] == 'E')
		path_check(data, x + 1, y);
	if (data->mapcpy[y - 1][x] == '0' || data->mapcpy[y - 1][x] == 'C' \
		|| data->mapcpy[y - 1][x] == 'E')
		path_check(data, x, y - 1);
	if (data->mapcpy[y + 1][x] == '0' || data->mapcpy[y + 1][x] == 'C' \
		|| data->mapcpy[y + 1][x] == 'E')
		path_check(data, x, y + 1);
}

/*check if the path of the player is valid*/
void	path_check(t_data *data, int x, int y)
{
	if (data->mapcpy[y][x] == 'P')
	{
		data->mapcpy[y][x] = 'X';
		data->map.p -= 1;
	}
	else if (data->mapcpy[y][x] == 'C')
	{
		data->mapcpy[y][x] = 'X';
		data->map.c -= 1;
	}
	else if (data->mapcpy[y][x] == 'E')
	{
		data->mapcpy[y][x] = 'X';
		data->map.e -= 1;
		return ;
	}
	else if (data->mapcpy[y][x] == '0')
		data->mapcpy[y][x] = 'X';
	recursive_call(data, x, y);
}
