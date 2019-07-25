/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 13:39:50 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/08 21:12:28 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(char a, char b, char c, char d)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(' ');
	ft_putchar(c);
	ft_putchar(d);
}

void	ft_last_block(char a, char b)
{
	char	c;
	char	d;

	c = a;
	while (c <= '9')
	{
		d = b + 1;
		while (d <= '9')
		{
			ft_print_numbers(a, b, c, d);
			if (!(a == '9' && b == '8' && c == '9' && d == '9'))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			d++;
		}
		c++;
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	a = '0';
	while (a <= '9')
	{
		b = '0';
		while (b <= '9')
		{
			ft_last_block(a, b);
			b++;
		}
		a++;
	}
	write(1, "\n", 1);
}
