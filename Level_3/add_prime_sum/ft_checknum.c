/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marahimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:02:45 by marahimi          #+#    #+#             */
/*   Updated: 2017/01/14 16:02:47 by marahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_checknum(char *s, size_t re, int neg, int pos)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' && (s[i + 1] >= 48 && s[i + 1] <= 57))
			neg = 1;
		if (s[i] == '+' && (s[i + 1] >= 48 && s[i + 1] <= 57))
			pos = 1;
		if (s[i] >= 48 && s[i] <= 57)
		{
			re = re * 10 + (s[i] - '0');
			if (!(s[i + 1] >= 48 && s[i + 1] <= 57))
				break ;
		}
		else if (!(ft_isspace(s[i])) && (!neg && !pos))
			break ;
		i++;
	}
	if (neg)
		re = -re;
	return (re);
}
