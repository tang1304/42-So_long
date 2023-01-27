/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:47:38 by tgellon           #+#    #+#             */
/*   Updated: 2023/01/27 17:31:19 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	x_wall_check(t_data *data)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(data->map.map[0]);
	ft_printf("%d\n", i);
	j = 0;
	while (data->map.map[j])
	{
		if (data->map.map[j][0] != '1' || data->map.map[j][i - 1] != '1')
		{
			ft_printf("Error\nLeft or right border not valid\n");
			return (0);
		}
		if (ft_strlen(data->map.map[j]) != i)
		{
			ft_printf("Error\nMap not rectangular\n");
			return (0);
		}
		j++;
	}
	return (1);
}

int	y_wall_check(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map.map[0][i])
	{
		if (data->map.map[0][i] != '1')
		{
			ft_printf("Error\nUpper border not valid\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (data->map.map[data->map.height - 1][i])
	{
		if (data->map.map[data->map.height - 1][i] != '1')
		{
			ft_printf("Error\nLower border not valid\n");
			return (0);
		}
		i++;
	}
	return (1);
}
