/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:08:44 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/18 15:48:06 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_node **a)
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
write(1, "ra\n", 4);
}