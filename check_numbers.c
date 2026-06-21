/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 12:53:54 by marvin            #+#    #+#             */
/*   Updated: 2026/06/19 12:53:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	str_to_int(char *str, int *error)
{
	int	result;
	int	sign;
	int	digit;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	*error = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		digit = str[i] - '0';
		if (result > (2147483647 - digit) / 10)
		{
			*error = 1;
			return (0);
		}
		result = result * 10 + digit;
		i++;
	}
	if (sign == -1 && result == 2147483647)
		return (-2147483647 - 1);
	return (result * sign);
}

int	is_duplicate(int *values, int count, int n)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (values[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int	*check_numbers(int argc, char **argv, int start)
{
	int *values;
	int i;
	int error;
	int n;

	values = malloc(sizeof(int) * (argc - start));
	if (!values)
		return (NULL);
	i = start;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			free(values);
			return (NULL);
		}
		n = str_to_int(argv[i], &error);
		if (error || is_duplicate(values, i - start, n))
		{
			free(values);
			return (NULL);
		}
		values[i - start] = n;
		i++;
	}
	return (values);
}