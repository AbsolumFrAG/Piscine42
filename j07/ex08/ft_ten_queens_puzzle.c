/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 10:12:47 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/14 15:49:22 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_dame[10];
int		g_comb;

void	ft_combinaisons(void)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (j == g_dame[i])
			{
				c = j + '0';
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int		ft_queen_free(int i, int n)
{
	int		k;

	k = 0;
	while (k < n)
	{
		if (g_dame[k] == i || g_dame[k] - i == k - n || g_dame[k] - i == n - k)
			return (0);
		k++;
	}
	return (1);
}

void	ft_placer_queen(int n)
{
	int		i;

	i = 0;
	if (n >= 10)
	{
		ft_combinaisons();
		g_comb++;
	}
	while (i < 10)
	{
		if (ft_queen_free(i, n) == 1)
		{
			g_dame[n] = i;
			ft_placer_queen(n + 1);
		}
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		n;

	n = 0;
	g_comb = 0;
	ft_placer_queen(n);
	return (g_comb);
}
