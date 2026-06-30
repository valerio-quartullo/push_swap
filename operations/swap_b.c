/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 11:17:57 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/30 11:17:57 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_node **b, t_count *counter)
{
	int	value_temp;
	int	rank_temp;

	if (!*b || !(*b)->next)
		return ;
	value_temp = (*b)->next->value;
	rank_temp = (*b)->next->rank;
	(*b)->next->value = (*b)->value;
	(*b)->next->rank = (*b)->rank;
	(*b)->value = value_temp;
	(*b)->rank = rank_temp;
	write(1, "sb\n", 3);
	counter->sb++;
	counter->tot++;
}
