/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:40:52 by nattia            #+#    #+#             */
/*   Updated: 2021/11/13 12:49:37 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	e;

	e = ft_strlen(s);
	while (e >= 0)
	{
		if (s[e] == (char)c)
			return ((char *)(s + e));
		e--;
	}
	return (0);
}
