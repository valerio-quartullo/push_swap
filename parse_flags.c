/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:48:25 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/30 11:42:10 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_len(t_node *a)
{
	int	n;

	n = 0;
	while (a)
	{
		n++;
		a = a->next;
	}
	return (n);
}

static int	count_inversions(t_node *a)
{
	int		count;
	t_node	*compare;

	count = 0;
	while (a)
	{
		compare = a->next;
		while (compare)
		{
			if (a->value > compare->value)
				count++;
			compare = compare->next;
		}
		a = a->next;
	}
	return (count);
}

float	measure_disorder(t_node *a)
{
	int	n;
	int	count;
	int	total;

	n = stack_len(a);
	if (n <= 1)
		return (0);
	count = count_inversions(a);
	total = n * (n - 1) / 2;
	return ((float)count / total);
}

static void	match_flag(char *flag, t_options *opt, int *strategy_count)
{
	if (!ft_strncmp(flag, "--bench", 7))
		opt->bench = 1;
	else if (!ft_strncmp(flag, "--simple", 8))
	{
		opt->strategy = ALGO_SIMPLE;
		(*strategy_count)++;
	}
	else if (!ft_strncmp(flag, "--medium", 8))
	{
		opt->strategy = ALGO_MEDIUM;
		(*strategy_count)++;
	}
	else if (!ft_strncmp(flag, "--complex", 9))
	{
		opt->strategy = ALGO_COMPLEX;
		(*strategy_count)++;
	}
	else if (!ft_strncmp(flag, "--adaptive", 10))
		(*strategy_count)++;
	else
		error_exit();
}

int	parse_flags(int argc, char **argv, t_options *opt)
{
	int	i;
	int	strategy_count;

	i = 1;
	strategy_count = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		match_flag(argv[i], opt, &strategy_count);
		i++;
	}
	if (strategy_count > 1)
		error_exit();
	return (i);
}
