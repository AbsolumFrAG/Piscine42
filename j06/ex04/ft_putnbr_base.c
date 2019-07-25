/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:04:27 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/13 15:59:59 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_base(char *base)
{
	int		i;
	int		a;

	i = 0;
	a = i + 1;
	if (base[0] == '\0' || base[1] == '\0')
	{
		return (0);
	}
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '.')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[a])
		{
			if (base[i] == base[a])
				return (0);
			a++;
		}
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_base(long n, int s, char *base)
{
	if (n >= s)
		ft_print_base(n / s, s, base);
	ft_putchar(base[n % s]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	s;
	long	n;

	s = 0;
	n = nbr;
	while (base[s])
		s++;
	if (ft_base(base))
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= (-1);
		}
		ft_print_base(n, s, base);
	}
}
