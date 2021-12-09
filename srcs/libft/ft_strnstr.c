/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:49:05 by nattia            #+#    #+#             */
/*   Updated: 2021/11/26 15:25:03 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	f;
	size_t	n_len;
	char	*s;

	s = (char *)haystack;
	n_len = ft_strlen(needle);
	if (*needle == '\0' || haystack == needle)
		return (s);
	i = 0;
	while (s[i] && i < len)
	{
		f = 0;
		while (needle[f] && s[i + f] && i + f < len && s[i + f] == needle[f])
			f++;
		if (f == n_len)
			return (s + i);
		i++;
	}
	return (0);
}
