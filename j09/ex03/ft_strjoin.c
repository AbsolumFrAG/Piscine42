/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:26:30 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/15 19:55:42 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strcpy(char *src, char *dest)
{
	int		i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_taille_strs(int size, char **strs)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (i < size)
	{
		nb = nb + ft_strlen(strs[i]);
		i++;
	}
	return (nb);
}

char	*ft_empty_mois(int size, char *resultat)
{
	if (size == 0)
	{
		resultat = malloc(sizeof(*resultat));
		resultat[0] = '\0';
		return (resultat);
	}
	else if (size < 0)
		return (0);
	return (0);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	char	*resultat;

	i = -1;
	j = 0;
	resultat = NULL;
	if (size <= 0)
		return (ft_empty_mois(size, resultat));
	resultat = (char*)malloc(sizeof(*resultat) * (ft_strlen(sep) * (size - 1)
				+ ft_taille_strs(size, strs) + 1));
	while (++i < size - 1)
	{
		ft_strcpy(strs[i], resultat + j);
		j = j + ft_strlen(strs[i]);
		ft_strcpy(sep, resultat + j);
		j = j + ft_strlen(sep);
	}
	ft_strcpy(strs[i], resultat + j);
	j = ft_strlen(strs[i]) + j + 1;
	resultat[j] = '\0';
	return (resultat);
}
