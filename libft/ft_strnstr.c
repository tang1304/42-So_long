/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:24:35 by tgellon           #+#    #+#             */
/*   Updated: 2022/11/21 13:06:13 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* MAN : The strnstr() function locates the first occurrence of the null-
     terminated string needle in the string haystack, where not more
     than len characters are searched.  Characters that appear after a
     `\0' character are not searched.*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if ((!haystack || !needle) && len == 0)
		return (NULL);
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (needle[j] == haystack[i] && needle[j] && i < len)
		{
			j++;
			i++;
		}
		if (needle[j] == '\0')
			return (&((char *)haystack)[i - j]);
		j = 0;
		k++;
		i = k;
	}
	return (NULL);
}
