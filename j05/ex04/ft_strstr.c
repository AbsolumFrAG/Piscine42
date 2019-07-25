/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:14:01 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/12 15:24:01 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		z;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i])
	{
		z = 0;
		while (to_find[z] == str[i + z])
		{
			z++;
			if (to_find[z] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
