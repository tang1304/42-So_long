/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:51:51 by tgellon           #+#    #+#             */
/*   Updated: 2023/02/16 09:47:42 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_sl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (dest = ft_strdup(s2));
	if (!s2)
		return (dest = s1);
	dest = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!dest)
		return (free(s1), NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++j])
	{
		dest[i] = s2[j];
		i++;
	}
	dest[i] = '\0';
	free(s1);
	return (dest);
}

void	ft_free_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

void	ft_free_maps(t_data *data)
{
	ft_free_map(data->map.map);
	ft_free_map(data->mapcpy);
}

void	data_init(t_data *data)
{
	data->map.height = 0;
	data->map.c = 0;
	data->map.e = 0;
	data->map.p = 0;
	data->moves = 0;
	data->map.c_count = 0;
}

int	map_empty_line_check(t_data *data)
{
	int	i;
	int	len;

	len = ft_strlen(data->tmp);
	i = -1;
	while (data->tmp[++i])
	{
		if ((data->tmp[i] == '\n' && data->tmp[i + 1] == '\n')
			|| data->tmp[0] == '\n')
		{
			free(data->tmp);
			ft_printf("Error\nEmpty line on the map\n");
			return (0);
		}
	}
	if (data->tmp[len - 1] == '\n')
	{
		free(data->tmp);
		ft_printf("Error\nEmpty line on the map\n");
		return (0);
	}
	return (1);
}
