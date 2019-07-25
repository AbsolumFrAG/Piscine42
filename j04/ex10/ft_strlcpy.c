/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:20:49 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/13 12:38:31 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	x;

	i = 0;
	x = 0;
	while (src[i])
	{
		i++;
	}
	if (size > 0)
	{
		while (src[x] != '\0' && x < size - 1)
		{
			dest[x] = src[x];
			x++;
		}
		dest[x] = '\0';
	}
	return (i);
}
