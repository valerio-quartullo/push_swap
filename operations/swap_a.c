/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 11:15:25 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/30 11:15:25 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node **a, t_count *counter)
{
	int	value_temp;
	int	rank_temp;

	if (!*a || !(*a)->next)
		return ;
	value_temp = (*a)->next->value;
	rank_temp = (*a)->next->rank;
	(*a)->next->value = (*a)->value;
	(*a)->next->rank = (*a)->rank;
	(*a)->value = value_temp;
	(*a)->rank = rank_temp;
	write(1, "sa\n", 3);
	counter->sa++;
	counter->tot++;
}
