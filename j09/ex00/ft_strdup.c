/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:59:55 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/17 09:02:16 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*s1;

	i = 0;
	len = 0;
	while (src[len] != 0)
		len++;
	if (!(s1 = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		s1[i] = src[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
