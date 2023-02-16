/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:47:38 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/15 16:42:41 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	path_check(t_data *data, int x, int y);

/*checks there are only '1' on the first and last column */
int	x_wall_check(t_data *data)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(data->map.map[0]);
	j = 0;
	while (data->map.map[j])
	{
		if (data->map.map[j][0] != '1' || data->map.map[j][i - 1] != '1')
		{
			ft_free_maps(data);
			ft_printf("Error\nLeft or right border not valid\n");
			return (0);
		}
		if (ft_strlen(data->map.map[j]) != i)
		{
			ft_free_maps(data);
			ft_printf("Error\nMap not rectangular\n");
			return (0);
		}
		j++;
	}
	data->map.width = i;
	return (1);
}

/*checks there are only '1' on the first and last line */
int	y_wall_check(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map.map[0][i])
	{
		if (data->map.map[0][i] != '1')
		{
			ft_free_maps(data);
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
			ft_free_maps(data);
			ft_printf("Error\nLower border not valid\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static void	path_check_2(t_data *data, int x, int y)
{
	if (data->mapcpy[y][x - 1] == '0' || data->mapcpy[y][x - 1] == 'C'
		|| data->mapcpy[y][x - 1] == 'E')
		path_check(data, x - 1, y);
	if (data->mapcpy[y][x + 1] == '0' || data->mapcpy[y][x + 1] == 'C'
		|| data->mapcpy[y][x + 1] == 'E')
		path_check(data, x + 1, y);
	if (data->mapcpy[y - 1][x] == '0' || data->mapcpy[y - 1][x] == 'C'
		|| data->mapcpy[y - 1][x] == 'E')
		path_check(data, x, y - 1);
	if (data->mapcpy[y + 1][x] == '0' || data->mapcpy[y + 1][x] == 'C'
		|| data->mapcpy[y + 1][x] == 'E')
		path_check(data, x, y + 1);
}

/*check if the path of the player is valid*/
static void	path_check(t_data *data, int x, int y)
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
	path_check_2(data, x, y);
}

/*Puts the string on a **char, and does the checks above */
int	map_parsing(t_data *data)
{
	data->map.map = ft_split(data->tmp, '\n');
	if (!data->map.map)
		return (free(data->tmp), 0);
	data->mapcpy = ft_split(data->tmp, '\n');
	if (!data->mapcpy)
	{
		free(data->tmp);
		ft_free_map(data->map.map);
		return (0);
	}
	free(data->tmp);
	if (!x_wall_check(data))
		return (0);
	if (!y_wall_check(data))
		return (0);
	get_p_position(data);
	data->c_nbr = data->map.c;
	path_check(data, data->map.p_x, data->map.p_y);
	if (data->map.c != 0 || data->map.p != 0 || data->map.e != 0)
	{
		ft_printf("Error\nPath not valid\n");
		ft_free_maps(data);
		return (0);
	}
	return (1);
}
