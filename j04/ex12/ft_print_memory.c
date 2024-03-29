/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 09:37:26 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/12 08:41:26 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i += 1;
	}
}

void	ft_hexa_number(int nb, char *base, int l, char *lead)
{
	long	n;
	long	n2;
	int		i;

	i = 1;
	n = nb;
	if (n < 0)
		n = 256 + n;
	n2 = n;
	while (n > l - 1)
	{
		n = n / l;
		i = i * l;
		lead += 1;
	}
	ft_putstr(lead + 1);
	while (i > 0)
	{
		ft_putchar(base[(n2 / i)]);
		n2 = n2 % i;
		i = i / l;
	}
}

void	data(char *buf, char *src, int l)
{
	int		i;

	buf[0] = ' ';
	i = 0;
	while (i < l)
	{
		buf[i + 1] = *(src + i) < ' ' || *(src + i) >= 127 ? '.' : *(src + i);
		i += 1;
	}
	buf[i + 1] = '\n';
	buf[i + 2] = '\0';
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	char			c;
	char			buf[20];

	i = 0;
	while (i < size)
	{
		ft_hexa_number(i, "0123456789abcdef", 16, "00000000");
		ft_putstr(": ");
		j = 0;
		while (i + j < size && j < 16)
		{
			c = *(char*)(addr + i + j);
			ft_hexa_number(c, "0123456789abcdef", 16, "00");
			if (j++ != 0 && j % 2 == 0)
				ft_putchar(' ');
		}
		data(buf, (char*)(addr + i), j);
		while (j++ < 16)
			ft_putstr(j % 2 == 0 ? "	" : "	");
		ft_putstr(buf);
		i += 16;
	}
	return (addr);
}
