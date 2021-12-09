/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putusg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:57:47 by nattia            #+#    #+#             */
/*   Updated: 2021/12/07 17:58:11 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(unsigned int n)
{
	int	l;

	l = 0;
	while (n)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

static char	*ft_itoa_usg(unsigned int n)
{
	char			*rtn;
	unsigned int	l;

	if (!n)
		return (ft_strdup("0"));
	l = len(n);
	rtn = (char *)malloc(sizeof(char) * l + 1);
	if (!rtn)
		return (NULL);
	rtn[l] = '\0';
	while (l--)
	{
		rtn[l] = (n % 10) + '0';
		n = n / 10;
	}
	return (rtn);
}

int	ft_putusg(unsigned int u)
{
	char	*nb;
	int		size;

	nb = ft_itoa_usg(u);
	size = ft_putstr(nb);
	free(nb);
	return (size);
}
