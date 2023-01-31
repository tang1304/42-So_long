/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:26:21 by tgellon           #+#    #+#             */
/*   Updated: 2023/01/31 17:18:54 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhook(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		ft_printf("ESC pressed\n");
		ft_close(data);
	}
	if (keycode == W)
	{
	}
	return (0);
}
