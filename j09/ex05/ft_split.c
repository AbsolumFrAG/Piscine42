/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 10:02:19 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/20 10:09:40 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_find_sep(char s,char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (s == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_index(char *str, char *charset)
{
	int		i;
	int		index;

	i = 0;
	index = 0;
	while (str[i])
	{
		while (str[i] && ft_find_sep(str[i], charset) == 1)
			i++;
		if (str[i] && ft_find_sep(str[i], charset) == 0)
		{
			index++;
			while (str[i] && ft_find_sep(str[i], charset) == 0)
				i++;
		}
	}
	return (index);
}

char	*ft_malloc(char *str, char *charset)
{
	char	*size;
	int		i;

	i = 0;
	while (str[i] && ft_find_sep(str[i], charset) == 0)
		i++;
	size = (char*)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && ft_find_sep(str[i], charset) == 0)
	{
		size[i] = str[i];
		i++;
	}
	size[i] = 0;
	return (size);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		i;
	int		k;

	i = 0;
	k = 0;
	array = (char **)malloc(sizeof(char *) * (ft_index(str, charset) + 1));
	if (!array)
		return (0);
	while (str[k])
	{
		while (str[k] && ft_find_sep(str[k], charset) == 1)
			k++;
		if (str[k] && ft_find_sep(str[k], charset) == 0)
		{
			array[i] = ft_malloc(str + k, charset);
			i++;
			while (str[k] && ft_find_sep(str[k], charset) == 0)
				k++;
		}
	}
	array[i] = NULL;
	return (array);
}
