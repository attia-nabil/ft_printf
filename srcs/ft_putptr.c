/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:57:35 by nattia            #+#    #+#             */
/*   Updated: 2021/12/07 17:58:11 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_size(unsigned long n)
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

static void	ft_puthex_ptr_rec(unsigned long n, char *base)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n > 15)
		ft_puthex_ptr_rec(n / 16, base);
	ft_putchar(base[n % 16]);
}

static int	ft_puthex_ptr(unsigned long n, char *base)
{
	if (n == 0)
		return (ft_putchar('0'));
	ft_puthex_ptr_rec(n, base);
	return (ft_get_size(n));
}

int	ft_putptr(unsigned long p)
{
	return (ft_putstr("0x") + ft_puthex_ptr(p, "0123456789abcdef"));
}
