/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltigroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:46:04 by ltigroud          #+#    #+#             */
/*   Updated: 2019/07/12 14:31:50 by ltigroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int		a;

	a = 0;
	while (s1[a] == s2[a] && s1[a] && s2[a])
		a++;
	return (s1[a] - s2[a]);
}
