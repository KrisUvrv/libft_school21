/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebloodbe <ebloodbe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:44:51 by ebloodbe          #+#    #+#             */
/*   Updated: 2021/10/22 10:43:41 by ebloodbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		i = ft_strlen(s);
	else
		i = len;
	str = (char *)malloc(sizeof(*s) * (i + 1));
	if (!str)
		return (NULL);
	if (i == 0)
		str[0] = 0;
	else
		ft_strlcpy(str, (char *)(s + start), i + 1);
	return (str);
}
