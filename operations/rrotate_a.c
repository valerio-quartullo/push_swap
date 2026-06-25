/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:05:52 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/25 15:03:34 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_node **a, t_count *counter)
{
t_node *last;
t_node	*prev;

if (!*a || !(*a)->next)
	return ;
prev = *a;
last = (*a)->next;
while (last->next)
{
	prev = last;
	last = last->next;
}
prev->next = NULL;
last->next = *a;
*a = last;
write(1, "rra\n", 4);
counter-> rra ++;
counter-> tot ++;
}
