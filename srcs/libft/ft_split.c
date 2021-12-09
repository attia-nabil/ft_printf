/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <nattia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:53:19 by nattia            #+#    #+#             */
/*   Updated: 2021/12/01 12:05:38 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			w++;
		i++;
	}
	return (w);
}

static size_t	words_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	leak(char **split, size_t w)
{
	size_t	i;

	i = -1;
	while (++i < w)
		free(split[i]);
	free(split);
}

static void	write_split(char **split, char const *s, size_t w, char const c)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = -1;
	while (++i < w)
	{
		while (*s == c)
			s++;
		l = words_len(s, c);
		split[i] = (char *)malloc(sizeof(char) * (l + 1));
		if (!split[i])
			leak(split, i);
		j = 0;
		while (j < l)
			split[i][j++] = *s++;
		split[i][j] = '\0';
	}
	split[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	w;
	char	**rtn;

	if (!s)
		return (NULL);
	w = count_words(s, c);
	rtn = (char **)malloc(sizeof(char *) * (w + 1));
	if (!rtn)
		return (NULL);
	write_split(rtn, s, w, c);
	rtn[w] = 0;
	return (rtn);
}
