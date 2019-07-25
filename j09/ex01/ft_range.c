/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:32:45 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/17 12:11:10 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*range;
	int		size;
	int		i;

	i = 0;
	if (min >= max)
		return (NULL);
	size = max - min;
	if (!(range = (int*)malloc(sizeof(*range) * size)))
		return (0);
	while (i < size)
	{
		range[i] = min;
		i++;
		min++;
	}
	return (range);
}
