/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 20:57:29 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/13 18:14:32 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hexa(unsigned char nb)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[nb / 16]);
	ft_putchar(hex[nb % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (((str[i] < 32) && str[i] >= 0) || str[i] == 127)
		{
			ft_putchar('\\');
			ft_print_hexa(str[i]);
		}
		else if (str[i] < 0)
			ft_print_hexa(str[i] + 256);
		else
			ft_putchar(str[i]);
		i++;
	}
}
