/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:26:21 by tgellon           #+#    #+#             */
/*   Updated: 2023/01/26 13:29:48 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keyhook(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		ft_printf("ESC pressed\n");
		ft_close(data);
	}
	if (keycode == W)
	{
		;
	}
	return (0);
}
