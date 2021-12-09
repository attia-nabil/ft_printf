/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:57:15 by nattia            #+#    #+#             */
/*   Updated: 2021/12/07 17:58:11 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_size(unsigned int n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		size++;
		n = n / 16;
	}
	return (size);
}

static void	ft_puthex_rec(unsigned int n, char *base)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n > 15)
		ft_puthex_rec(n / 16, base);
	ft_putchar(base[n % 16]);
}

int	ft_puthex(unsigned int n, char *base)
{
	if (n == 0)
		return (ft_putchar('0'));
	ft_puthex_rec(n, base);
	return (ft_get_size(n));
}
