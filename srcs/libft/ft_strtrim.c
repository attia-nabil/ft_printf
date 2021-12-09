/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:54:13 by nattia            #+#    #+#             */
/*   Updated: 2021/12/01 14:12:21 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strstart(char *str, char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && set[j])
	{
		if (str[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (&str[i]);
}

static int	strend(char *str, char *set)
{
	int		i;
	int		j;

	i = ft_strlen(str);
	j = 0;
	while (i > 0 && set[j])
	{
		if (str[i - 1] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*tab;
	char		*delt;
	char		*ptr;
	char		*string;
	size_t		i;

	tab = (char *)s1;
	delt = (char *)set;
	if (!s1 || !set)
		return (NULL);
	string = strstart(tab, delt);
	i = strend(string, delt);
	ptr = malloc(sizeof(char) * i + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, string, i);
	ptr[i] = '\0';
	return (ptr);
}
