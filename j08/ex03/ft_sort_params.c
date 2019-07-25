/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:23:15 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/16 14:36:54 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_params(int argc, char **argv)
{
	int		i;
	char	*p;

	i = 0;
	while (i < argc - 3)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			p = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = p;
			if (i > 0)
				i = i - 2;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	ft_sort_params(argc, argv + 1);
	while (i <= argc - 1)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
