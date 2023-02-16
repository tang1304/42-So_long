/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:14:30 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/16 09:48:15 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Gets the coordinates of the P*/
void	get_p_position(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (data->map.map[++j])
	{
		i = -1;
		while (data->map.map[j][++i])
		{
			if (data->map.map[j][i] == 'P')
			{
				data->map.p_x = i;
				data->map.p_y = j;
			}
		}
	}
}

/*Puts all the lines of the .ber file in a string*/
static int	get_map(t_data *data, int fd)
{
	char	*temp;

	temp = get_next_line(fd);
	if (!temp)
		return (0);
	data->tmp = ft_strdup(temp);
	if (!data->tmp)
		return (free(temp), 0);
	free(temp);
	while (temp != NULL)
	{
		temp = get_next_line(fd);
		data->map.height++;
		data->tmp = ft_strjoin_sl(data->tmp, temp);
		if (!data->tmp)
			return (free(temp), 0);
		free(temp);
	}
	return (1);
}

/*check the chars forming the map*/
static int	map_char_check(t_data *data)
{
	int	i;

	i = -1;
	while (data->tmp[++i])
	{
		if (data->tmp[i] != '0' && data->tmp[i] != '1' && data->tmp[i] != 'C'
			&& data->tmp[i] != 'E' && data->tmp[i] != 'P'
			&& data->tmp[i] != '\n')
		{
			ft_printf("Error\nOnly '0', '1', 'P', 'C', 'E' authorized\n");
			return (0);
		}
		if (data->tmp[i] == 'C')
			data->map.c++;
		if (data->tmp[i] == 'E')
			data->map.e++;
		if (data->tmp[i] == 'P')
			data->map.p++;
	}
	if (data->map.c < 1 || data->map.e != 1 || data->map.p != 1)
	{
		ft_printf("Error\nOnly 1 'P', 1 'E', 1 or more 'C' authorized\n");
		return (0);
	}
	return (1);
}

/*Check the .ber format*/
static int	map_format(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (argv[i - 1] == 'r' && argv[i - 2] == 'e' && argv[i - 3] == 'b'
		&& argv[i - 4] == '.')
		return (1);
	ft_printf("Error\nWrong map file format\n");
	return (0);
}

/*main fuction to check the map*/
int	map_init(t_data *data, int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf("Error\nWrong argument\n");
		return (0);
	}
	if (!map_format(argv[1]))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (!get_map(data, fd))
	{
		ft_printf("Error\nGet_map crashed\n");
		return (close(fd), 0);
	}
	close(fd);
	if (!map_char_check(data))
		return (free(data->tmp), 0);
	if (!map_empty_line_check(data))
		return (0);
	if (!map_parsing(data))
		return (0);
	return (1);
}
