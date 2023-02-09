/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:28:46 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/09 16:36:07 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	anim_player_l(t_data *data, int x, int y)
{
	data->p_frames = 0;
	while (data->p_frames < ANIMATION * 10)
		data->p_frames++;
	if (!put_img(data, COLLECTIBLE, data->map.p_x, data->map.p_y))//P_RL_OUT
		return (0);
	if (data->map.map[data->map.p_y + y][data->map.p_x + x] == 'C')
	{
		if (!put_img(data, COLLECTIBLE, data->map.p_x - 1, data->map.p_y))//C_RL
			return (0);
	}
	else
	{
		if (!put_img(data, COLLECTIBLE, data->map.p_x - 1, data->map.p_y))//P_RL_IN
			return (0);
	}
	while (data->p_frames < (ANIMATION * 20))
		data->p_frames++;
	if (!put_img(data, FLOOR, data->map.p_x, data->map.p_y))
		return (0);
	if (!put_img(data, P_LEFT_STILL, data->map.p_x - 1, data->map.p_y))
		return (0);
	ft_printf("ici\n");
	return (1);
}

static int	anim_player_r(t_data *data, int x, int y)
{
	data->p_frames = 0;
	while (data->p_frames < ANIMATION)
		data->p_frames++;
	if (!put_img(data, COLLECTIBLE, data->map.p_x, data->map.p_y))//P_LR_OUT
		return (0);
	if (data->map.map[data->map.p_y + y][data->map.p_x + x] == 'C')
	{
		if (!put_img(data, COLLECTIBLE, data->map.p_x + 1, data->map.p_y))//C_LR
			return (0);
	}
	else
	{
		if (!put_img(data, COLLECTIBLE, data->map.p_x + 1, data->map.p_y))//P_LR_IN
			return (0);
	}
	while (data->p_frames < (ANIMATION * 2))
		data->p_frames++;
	if (!put_img(data, FLOOR, data->map.p_x, data->map.p_y))
		return (0);
	if (!put_img(data, P_RIGHT_STILL, data->map.p_x + 1, data->map.p_y))
		return (0);
	return (1);
}

static int	anim_player_u(t_data *data, int x, int y)
{
	data->p_frames = 0;
	while (data->p_frames < ANIMATION)
		data->p_frames++;
	if (!put_img(data, COLLECTIBLE, data->map.p_x, data->map.p_y))//P_DU_OUT
		return (0);
	if (data->map.map[data->map.p_y + y][data->map.p_x + x] == 'C')
	{
		if (!put_img(data, COLLECTIBLE, data->map.p_x, data->map.p_y - 1))//C_DU
			return (0);
	}
	else
	{
		if (!put_img(data, COLLECTIBLE, data->map.p_x, data->map.p_y - 1))//P_DU_IN
			return (0);
	}
	while (data->p_frames < (ANIMATION * 2))
		data->p_frames++;
	if (!put_img(data, FLOOR, data->map.p_x, data->map.p_y))
		return (0);
	if (!put_img(data, P_BACK_STILL, data->map.p_x, data->map.p_y - 1))
		return (0);
	return (1);
}

// static int	anim_player_d(t_data *data, int x, int y)
// {
// 	data->p_frames = 0;
// 	while (data->p_frames < ANIMATION)
// 		data->p_frames++;
// 	if (!put_img(data, COLLECTIBLE, data->map.p_x, data->map.p_y))//P_UD_OUT
// 		return (0);
// 	if (data->map.map[data->map.p_y + y][data->map.p_x + x] == 'C')
// 	{
// 		if (!put_img(data, COLLECTIBLE, data->map.p_x, data->map.p_y + 1))//C_UD
// 			return (0);
// 	}
// 	else
// 	{
// 		if (!put_img(data, COLLECTIBLE, data->map.p_x, data->map.p_y + 1))//P_UD_IN
// 			return (0);
// 	}
// 	while (data->p_frames < (ANIMATION * 2))
// 		data->p_frames++;
// 	if (!put_img(data, FLOOR, data->map.p_x, data->map.p_y))
// 		return (0);
// 	if (!put_img(data, P_FRONT_STILL, data->map.p_x, data->map.p_y + 1))
// 		return (0);
// 	return (1);
// }

static int	anim_player_d(t_data *data, int x, int y)
{
	data->p_frames = 0;
	while (data->p_frames <= ANIMATION * 10)
	{
		if (data->p_frames == (ANIMATION * 5))
		{
			if (!put_img(data, COLLECTIBLE, data->map.p_x, data->map.p_y))//P_UD_OUT
				return (0);
			if (data->map.map[data->map.p_y + y][data->map.p_x + x] == 'C')
			{
				if (!put_img(data, COLLECTIBLE, data->map.p_x, data->map.p_y + 1))//C_UD
					return (0);
			}
			else
			{
				if (!put_img(data, COLLECTIBLE, data->map.p_x, data->map.p_y + 1))//P_UD_IN
					return (0);
			}
		}
		if (data->p_frames == ANIMATION * 10)
		{
			if (!put_img(data, FLOOR, data->map.p_x, data->map.p_y))
				return (0);
			if (!put_img(data, P_FRONT_STILL, data->map.p_x, data->map.p_y + 1))
				return (0);
		}
		data->p_frames++;
	}
	return (1);
}

int	anim_player(t_data *data, int keycode, int x, int y)
{
	if (keycode == A)
		anim_player_l(data, x, y);
	if (keycode == D)
		anim_player_r(data, x, y);
	if (keycode == W)
		anim_player_u(data, x, y);
	if (keycode == S)
		anim_player_d(data, x, y);
	return (1);
}
