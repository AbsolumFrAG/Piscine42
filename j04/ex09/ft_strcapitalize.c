/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:40:14 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/10 18:35:57 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alphanumeric(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int		maj(char c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	return (0);
}

char	min(char c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		mot;

	i = 0;
	mot = 0;
	while (str[i])
	{
		if ((min(str[i])) && (mot == 0))
			str[i] = str[i] - 32;
		else if ((maj(str[i])) && (mot == 1))
			str[i] = str[i] + 32;
		if (!(is_alphanumeric(str[i])))
			mot = 0;
		else
			mot = 1;
		i++;
	}
	return (str);
}
