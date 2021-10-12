/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebloodbe <ebloodbe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:46:59 by ebloodbe          #+#    #+#             */
/*   Updated: 2021/10/09 19:22:16 by ebloodbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_int_to_str(char *str, int n, int size)
{
	int				i;
	unsigned int	num;

	i = size - 1;
	if (n < 0)
	{
		str[0] = '-';
		num = n * -1;
	}
	else
		num = n;
	str[i] = '\0';
	i--;
	while (i >= 0 && (n >= 0 || str[i] != '-'))
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (str);
}

static char	*ft_str_alloc(int size)
{
	char	*str;

	str = NULL;
	str = (char *)malloc(sizeof(char) * size);
	return (str);
}

static int	ft_count_digits(int n)
{
	unsigned int	num;
	int				count;

	count = 0;
	if (n < 0)
	{
		count++;
		num = n * -1;
	}
	else
		num = n;
	while (num >= 10)
	{
		num /= 10;
		count++;
	}
	count += 2;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	char	*int_to_str;

	size = ft_count_digits(n);
	str = ft_str_alloc(size);
	if (!str)
		return (NULL);
	int_to_str = ft_int_to_str(str, n, size);
	return (int_to_str);
}
