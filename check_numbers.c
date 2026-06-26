/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 12:53:54 by marvin            #+#    #+#             */
/*   Updated: 2026/06/26 11:20:08 by vquartul         ###   ########.fr       */
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

static int	parse_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	str_to_int(char *str, int *error)
{
	int	result;
	int	sign;
	int	digit;
	int	i;

	result = 0;
	i = 0;
	*error = 0;
	sign = parse_sign(str, &i);
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

static int	validate_one(char *str, int *values, int count, int *error)
{
	int	n;

	if (!is_valid_number(str))
	{
		*error = 1;
		return (0);
	}
	n = str_to_int(str, error);
	if (*error || is_duplicate(values, count, n))
	{
		*error = 1;
		return (0);
	}
	return (n);
}

int	*check_numbers(int argc, char **argv, int start)
{
	int		*values;
	int		i;
	int		error;

	values = malloc(sizeof(int) * (argc - start));
	if (!values)
		return (NULL);
	i = start;
	while (i < argc)
	{
		error = 0;
		values[i - start] = validate_one(argv[i], values, i - start, &error);
		if (error)
		{
			free(values);
			return (NULL);
		}
		i++;
	}
	return (values);
}
