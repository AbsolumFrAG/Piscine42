/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 10:00:20 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/20 15:00:30 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_check(char *str, char *base, int size_base)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < size_base)
		{
			if (str[i] == base[j])
				count++;
			j++;
		}
		if (count != i + 1)
			return (count);
		i++;
	}
	return (count);
}

int		ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0 || nb == 1)
		return (1);
	if (power == 1)
		return (nb);
	else
		return (nb = nb * ft_power(nb, power - 1));
}

long	ft_str_to_int(char *str, char *base, int size_str, int size_base)
{
	int		i;
	int		j;
	long	result;

	i = 0;
	result = 0;
	while (i < size_str)
	{
		j = 0;
		while (str[i] != base[j])
			j++;
		result = result + j * ft_power(size_base, size_str - 1 - i);
		i++;
	}
	return (result);
}

int		ft_atoi_base(char *str, char *base, int size_bf)
{
	int		size_str;
	int		signe;
	int		i;

	signe = 0;
	i = 0;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			signe++;
		i++;
	}
	size_str = ft_str_check(str + i, base, size_bf);
	if (size_str > 0)
	{
		if (signe % 2)
			return (-1 * ft_str_to_int(str + i, base, size_str, size_bf));
		else
			return (ft_str_to_int(str + i, base, size_str, size_bf));
	}
	return (0);
}
