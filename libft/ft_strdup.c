/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 12:18:27 by vquartul          #+#    #+#             */
/*   Updated: 2026/05/21 12:18:30 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s) + 1;
	copy = malloc(len);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, len);
	return (copy);
}
