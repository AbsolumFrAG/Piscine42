/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:35:31 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/13 08:51:36 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	ls;
	unsigned int	i;

	len_dest = 0;
	ls = 0;
	i = 0;
	while (src[ls] != '\0')
		ls++;
	while (dest[len_dest] != '\0')
		len_dest++;
	if (size == 0)
		return (ls);
	if (size <= len_dest)
		return (ls + size);
	while (src[i] && i + 1 < size)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + ls);
}
