/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebloodbe <ebloodbe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:22:40 by ebloodbe          #+#    #+#             */
/*   Updated: 2021/10/11 17:11:22 by ebloodbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i] == needle[j] && haystack[i] != '\0'
			&& needle[j] != '\0' && i < len)
		{
			i++;
			j++;
		}
		if (needle[j] == '\0' && i - j < len)
			return ((char *)haystack + (i - j));
		i -= j;
		i++;
	}
	return (NULL);
}
