/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:28:46 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/14 14:47:47 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	anim_player_l(t_data *data, int x, int y)
{
	if (data->map.map[data->map.p_y + y][data->map.p_x + x] == 'C')
	{
		if (!put_img(data, P_RL_OUT, data->map.p_x, data->map.p_y))
			return (0);
		if (!put_img(data, C_RL, data->map.p_x - 1, data->map.p_y))
			return (0);
		if (!put_img(data, FLOOR, data->map.p_x, data->map.p_y))
			return (0);
	}
	else
	{
		if (!put_img(data, P_RL_OUT, data->map.p_x, data->map.p_y))
			return (0);
		if (!put_img(data, P_RL_IN, data->map.p_x - 1, data->map.p_y))
			return (0);
		if (!put_img(data, FLOOR, data->map.p_x, data->map.p_y))
			return (0);
	}
	usleep(SLEEP);
	if (!put_img(data, P_LEFT_STILL, data->map.p_x - 1, data->map.p_y))
		return (0);
	return (1);
}

static int	anim_player_r(t_data *data, int x, int y)
{
	if (data->map.map[data->map.p_y + y][data->map.p_x + x] == 'C')
	{
		if (!put_img(data, P_LR_OUT, data->map.p_x, data->map.p_y))
			return (0);
		if (!put_img(data, C_LR, data->map.p_x + 1, data->map.p_y))
			return (0);
		if (!put_img(data, FLOOR, data->map.p_x, data->map.p_y))
			return (0);
	}
	else
	{
		if (!put_img(data, P_LR_OUT, data->map.p_x, data->map.p_y))
			return (0);
		if (!put_img(data, P_LR_IN, data->map.p_x + 1, data->map.p_y))
			return (0);
		if (!put_img(data, FLOOR, data->map.p_x, data->map.p_y))
			return (0);
	}
	usleep(SLEEP);
	if (!put_img(data, P_RIGHT_STILL, data->map.p_x + 1, data->map.p_y))
		return (0);
	return (1);
}

static int	anim_player_u(t_data *data, int x, int y)
{
	if (data->map.map[data->map.p_y + y][data->map.p_x + x] == 'C')
	{
		if (!put_img(data, P_DU_OUT, data->map.p_x, data->map.p_y))
			return (0);
		if (!put_img(data, C_DU, data->map.p_x, data->map.p_y - 1))
			return (0);
		if (!put_img(data, FLOOR, data->map.p_x, data->map.p_y))
			return (0);
	}
	else
	{
		if (!put_img(data, P_DU_OUT, data->map.p_x, data->map.p_y))
			return (0);
		if (!put_img(data, P_DU_IN, data->map.p_x, data->map.p_y - 1))
			return (0);
		if (!put_img(data, FLOOR, data->map.p_x, data->map.p_y))
			return (0);
	}
	usleep(SLEEP);
	if (!put_img(data, P_BACK_STILL, data->map.p_x, data->map.p_y - 1))
		return (0);
	return (1);
}

static int	anim_player_d(t_data *data, int x, int y)
{
	if (data->map.map[data->map.p_y + y][data->map.p_x + x] == 'C')
	{
		if (!put_img(data, P_UD_OUT, data->map.p_x, data->map.p_y))
			return (0);
		if (!put_img(data, C_UD, data->map.p_x, data->map.p_y + 1))
			return (0);
		if (!put_img(data, FLOOR, data->map.p_x, data->map.p_y))
			return (0);
	}
	else
	{
		if (!put_img(data, P_UD_OUT, data->map.p_x, data->map.p_y))
			return (0);
		if (!put_img(data, P_UD_IN, data->map.p_x, data->map.p_y + 1))
			return (0);
		if (!put_img(data, FLOOR, data->map.p_x, data->map.p_y))
			return (0);
	}
	usleep(SLEEP);
	if (!put_img(data, P_FRONT_STILL, data->map.p_x, data->map.p_y + 1))
		return (0);
	return (1);
}

int	anim_player(t_data *data, int keycode, int x, int y)
{
	int	tmp;

	if (keycode == A)
		tmp = anim_player_l(data, x, y);
	else if (keycode == D)
		tmp = anim_player_r(data, x, y);
	else if (keycode == W)
		tmp = anim_player_u(data, x, y);
	else if (keycode == S)
		tmp = anim_player_d(data, x, y);
	if (tmp == 0)
		return (0);
	return (1);
}
