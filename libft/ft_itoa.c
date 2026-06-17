/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 12:35:53 by vquartul          #+#    #+#             */
/*   Updated: 2026/05/22 12:36:07 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_numlen(long n)
{
	int	len;

	len = (n <= 0);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = (long)n;
	len = ft_numlen(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
		nb = -nb;
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[--len] = '0' + (nb % 10);
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
