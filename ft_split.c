/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebloodbe <ebloodbe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:46:51 by ebloodbe          #+#    #+#             */
/*   Updated: 2021/10/22 15:37:36 by ebloodbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_result_free(char **result, size_t lenght)
{
	size_t	i;

	i = 0;
	while (i < lenght - 1)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static int	ft_count_words(char const *s, char c)
{
	size_t	size;
	size_t	length;
	size_t	i;

	size = ft_strlen(s);
	length = 0;
	i = 0;
	while (i < size && s[i])
	{
		if (s[i] != c && i < size && s[i])
		{
			while (s[i] != c && i < size && s[i])
			{
				i++;
			}
			length++;
		}
		while (s[i] == c && i < size && s[i])
			i++;
	}
	return (length);
}

static char	**ft_result_alloc(char const *s, char c)
{
	char	**result;
	size_t	length;

	length = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * length + 1);
	return (result);
}

static int	ft_process(char const *s, char **result, char c)
{
	size_t	index;
	char	*element;

	index = 0;
	while (*s)
	{
		if (*s != c)
		{
			element = (char *)s;
			while (*element && *element != c)
				element++;
			result[index] = (char *)malloc(element - s + 1);
			if (!result[index])
			{
				ft_result_free(result, index - 1);
				return (0);
			}
			ft_strlcpy(result[index++], (char *)s, element - s + 1);
			s = element;
		}
		else
			s++;
	}
	result[index] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = ft_result_alloc(s, c);
	if (!result)
		return (NULL);
	if (ft_process(s, result, c) == 0)
		return (NULL);
	return (result);
}
