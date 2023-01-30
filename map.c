/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:14:30 by tgellon           #+#    #+#             */
/*   Updated: 2023/01/30 16:14:37 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_map(t_data *data, int fd)//TODO: verif des free
{
	char	*temp;

	data->map.height = 0;
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
		if (!temp)
			return (free(data_tmp), 0);
		data->map.height++;
		data->tmp = ft_strjoin_sl(data->tmp, temp);
		if (!data->tmp)
			return (free(temp), 0);
		free(temp);
	}
	return (1);
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
		return (0);//TODO remplacer par "exit(EXIT_FAILURE)"
	}
	if (!map_format(argv[1]))
		return (0);//TODO remplacer par "exit(EXIT_FAILURE)"
	fd = open(argv[1], O_RDONLY);
	if (!get_map(data, fd))
	{
		ft_printf("Error\nGet_map crashed\n");
		exit(EXIT_FAILURE);//TODO remplacer par "exit(EXIT_FAILURE)"
	}
	close(fd);
	if (!map_char_check(data))
		return (0);//TODO remplacer par "exit(EXIT_FAILURE)"
	if (!map_parsing(data))
		return (0);//TODO remplacer par "exit(EXIT_FAILURE)"
	return (1);
}
