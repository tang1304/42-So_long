/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:14:30 by tgellon           #+#    #+#             */
/*   Updated: 2023/01/27 17:31:25 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_parsing(t_data *data)
{
	int	i;

	i = 0;
	data->map.map = ft_split(data->tmp, '\n');
	if (!data->map.map)
		return (0);
	if (!y_wall_check(data))
		return (0);
//	ft_printf("ici\n");
	if (!x_wall_check(data))
		return (0);
	return (1);
}

static void	get_map(t_data *data, int fd)
{
	char	*temp;

	data->map.height = 0;
	temp = get_next_line(fd);
	data->tmp = ft_strdup(temp);
	free(temp);
	while (temp != NULL)
	{
		temp = get_next_line(fd);
		data->map.height++;
		data->tmp = ft_strjoin_sl(data->tmp, temp);
		free(temp);
	}
//	ft_printf("%s\n", data->temp);
}

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
			ft_printf("Error\nOnly '0', '1', 'P', 'C' and 'E' authorized\n");
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

int	map_init(t_data *data, int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf("Error\nWrong argument\n");
//		exit(EXIT_FAILURE);
		return (0);
	}
	if (!map_format(argv[1]))
//		exit(EXIT_FAILURE);
		return (0);
	fd = open(argv[1], O_RDONLY);
	get_map(data, fd);
	if (!&get_map)
	{
		ft_printf("Error\nGet_map crashed\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
	if (!map_char_check(data))
//		exit(EXIT_FAILURE);
		return (0);
	map_parsing(data);
	free(data->tmp);
	return (1);
}
