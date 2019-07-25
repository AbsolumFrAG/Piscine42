/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:54:47 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/18 11:32:35 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		*temp;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	temp = (int*)malloc(sizeof(*temp) * (max - min));
	if (!temp)
		return (-1);
	i = 0;
	while (min < max)
	{
		temp[i] = min;
		i++;
		min++;
	}
	*range = temp;
	return (i);
}
