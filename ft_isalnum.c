/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebloodbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:08:41 by ebloodbe          #+#    #+#             */
/*   Updated: 2021/10/05 12:20:15 by ebloodbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	i;
	int	j;

	i = ft_isalpha(c);
	j = ft_isdigit(c);
	if (i == 1 || j == 1)
		return (1);
	return (0);
}
