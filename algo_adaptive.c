/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:03:18 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/30 14:45:08 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_adaptive(t_node **a, t_node **b, t_count *counter, t_options *opt)
{
	if (opt->number <= 15 || (opt->number <= 100 && opt->order >= 0.85)
		|| (opt->number <= 500 && opt->order >= 0.95))
	{
		algo_simple(a, b, counter);
		printf("%d <= 15 - algo_simple", opt->number);
	}
	else
	{
		algo_medium(a, b, counter);
		printf("%d > 15 - algo_medium", opt->number);
	}
	printf("\n%d", counter->tot);
}
