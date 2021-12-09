/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <nattia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:53:04 by nattia            #+#    #+#             */
/*   Updated: 2021/12/01 12:25:33 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	len_and_sign(int *n, int *s, int *l, int *t)
{
	if (*n < 0)
	{
		*n = *n * -1;
		*s = 1;
	}
	while (*t)
	{
		*t = *t / 10;
		*l = *l + 1;
	}
	*l = *l + *s;
}

char	*ft_itoa(int n)
{
	int		t;
	int		s;
	int		l;
	char	*rtn;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	t = n;
	s = 0;
	l = 1;
	len_and_sign(&n, &s, &l, &t);
	rtn = (char *)malloc(sizeof(char) * l);
	if (!rtn)
		return (NULL);
	rtn[--l] = '\0';
	while (l--)
	{
		rtn[l] = (n % 10) + '0';
		n = n / 10;
	}
	if (s)
		rtn[0] = '-';
	return (rtn);
}
