/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:51:51 by tgellon           #+#    #+#             */
/*   Updated: 2023/01/27 13:32:49 by tgellon          ###   ########lyon.fr   */
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
