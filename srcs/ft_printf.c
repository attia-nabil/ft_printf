/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:19:49 by nattia            #+#    #+#             */
/*   Updated: 2021/12/08 21:19:56 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int	ft_eval_format(va_list args, char fs)
{
	int	r;

	r = 0;
	if (fs == 'c')
		r += ft_putchar(va_arg(args, int));
	else if (fs == 's')
		r += ft_putstr(va_arg(args, char *));
	else if (fs == 'd' || fs == 'i')
		r += ft_putnbr(va_arg(args, int));
	else if (fs == 'u')
		r += ft_putusg(va_arg(args, unsigned int));
	else if (fs == 'x')
		r += ft_puthex(va_arg(args, long), "0123456789abcdef");
	else if (fs == 'X')
		r += ft_puthex(va_arg(args, long), "0123456789ABCDEF");
	else if (fs == 'p')
		r += ft_putptr(va_arg(args, unsigned long));
	else if (fs == '%')
		r += ft_putper();
	return (r);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		r;

	i = -1;
	r = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			r += ft_eval_format(args, format[i + 1]);
			i++;
		}
		else
			r += ft_putchar(format[i]);
	}
	va_end(args);
	return (r);
}
