/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:48:25 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/17 17:30:01 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	parse_flags(int argc, char **argv, t_options *opt)
{
	int	i;
	int	strategy_count;

	i = 1;
	strategy_count = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!ft_strncmp(argv[i], "--bench", 7))
			opt->bench = 1;
		else if (!ft_strncmp(argv[i], "--simple", 8))
		{
			opt->strategy = ALGO_SIMPLE;
			strategy_count++;
		}
		else if (!ft_strncmp(argv[i], "--medium", 8))
		{
			opt->strategy = ALGO_MEDIUM;
			strategy_count++;
		}
		else if (!ft_strncmp(argv[i], "--complex", 9))
		{
			opt->strategy = ALGO_COMPLEX;
			strategy_count++;
		}
		else if (!ft_strncmp(argv[i], "--adaptive", 10))
			strategy_count++;
		else
			error_exit();
		i++;
	}
	if (strategy_count > 1)
		error_exit();
	return (i);
}
