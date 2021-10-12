/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebloodbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:57:05 by ebloodbe          #+#    #+#             */
/*   Updated: 2021/10/06 10:50:51 by ebloodbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dsize;

	dsize = 0;
	while (dst[dsize] && dsize < dstsize)
		dsize++;
	i = dsize;
	while (src[dsize - i] && dsize + 1 < dstsize)
	{
		dst[dsize] = src[dsize - i];
		dsize++;
	}
	if (i < dstsize)
		dst[dsize] = '\0';
	return (i + ft_strlen(src));
}
