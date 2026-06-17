/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:16:28 by vquartul          #+#    #+#             */
/*   Updated: 2026/05/22 12:16:32 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	ft_free(char **res, size_t i)
{
	while (i > 0)
		free(res[--i]);
	free(res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		len = ft_wordlen(s, c);
		res[i] = ft_substr(s, 0, len);
		if (!res[i])
			return (ft_free(res, i), NULL);
		s += len;
		i++;
	}
	res[i] = NULL;
	return (res);
}
