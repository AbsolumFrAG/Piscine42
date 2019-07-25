/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:17:25 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/18 12:55:31 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base, int size);

int		ft_check_base(char *base)
{
	int		i;
	int		j;
	int		size_b;

	i = 0;
	size_b = 0;
	while (base[size_b] != '\0')
	{
		if (base[size_b] == '+' || base[size_b] == '-' || \
				base[size_b] <= 32 || base[size_b] > 126)
			return (0);
		size_b++;
	}
	while (i < size_b - 1)
	{
		j = i + 1;
		while (j < size_b - 1)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (size_b);
}

char	*ft_base(int nb, int size_bt, char *base, int size_str)
{
	long	nbr;
	char	*str;
	int		i;

	nbr = nb;
	i = 0;
	if ((str = (char *)malloc(sizeof(*str) * (size_str + 1))) == NULL)
		return (NULL);
	if (nbr < 0)
	{
		str[i] = '-';
		nbr = -nbr;
		i++;
	}
	str[size_str] = '\0';
	size_str--;
	while (size_str >= i)
	{
		str[size_str] = base[nbr % size_bt];
		nbr = nbr / size_bt;
		size_str--;
	}
	return (str);
}

char	*ft_putnbr_base(int nbr, char *base, int size_bt)
{
	int		size_str;
	long	nb;

	size_str = 0;
	nb = nbr;
	if (nb < 0)
	{
		nb = -nb;
		size_str++;
	}
	while (nb >= size_bt)
	{
		nb = nb / size_bt;
		size_str++;
	}
	return (ft_base(nbr, size_bt, base, size_str + 1));
}

char	*ft_convert_base(char *nbr, char *bf, char *bt)
{
	int		i;
	int		size_bf;
	int		size_bt;
	char	*str;

	i = 0;
	size_bf = ft_check_base(bf);
	size_bt = ft_check_base(bt);
	if (size_bf > 1 && size_bt > 1)
	{
		str = ft_putnbr_base(ft_atoi_base(nbr, bf, size_bf), bt, size_bt);
		return (str);
	}
	return (NULL);
}
