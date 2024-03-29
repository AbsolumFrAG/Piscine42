/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:04:05 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/18 13:58:12 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int						ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int						ft_structure(t_stock_str *str, int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		if (!(str[i].copy = malloc(sizeof(char) * ft_strlen(av[i]) + 1)))
			return (0);
		while (av[i][j] != '\0')
		{
			str[i].copy[j] = av[i][j];
			j++;
		}
		str[i].copy[j] = 0;
		str[i].str = av[i];
		str[i].size = j;
		j = 0;
		i++;
	}
	str[i].size = 0;
	str[i].str = 0;
	str[i].copy = 0;
	return (1);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *str;

	if (!(str = malloc(sizeof(t_stock_str) * (ac + 1))))
	{
		str = 0;
		return (str);
	}
	if (ft_structure(str, ac, av) == 0)
	{
		str = 0;
		return (str);
	}
	return (str);
}
