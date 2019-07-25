/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 21:05:36 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/15 17:41:36 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		i;

	i = 0;
	if (nb > 0)
	{
		while (i * i < nb && i < 46341)
			i++;
		if (nb % i == 0)
			return (i);
		else
			return (0);
	}
	else
		return (0);
}

int		ft_is_prime(int nb)
{
	int		i;

	i = 3;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (ft_sqrt(nb) != 0)
		return (0);
	if (nb % 2 == 0)
		return (0);
	while (nb % i != 0 && i < nb)
	{
		i = i + 2;
		if (nb % i == 0 && i == nb)
			return (1);
	}
	return (0);
}
