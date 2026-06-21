/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:13:28 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/18 15:32:51 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_node **a, t_node **b, int *count)
{
	t_node	*moved;

	if (!*a)
		return ;
	moved = *a;
	*a = (*a)->next;
	moved->next = *b;
	*b = moved;
	write(1, "pb\n", 3);
	(*count)++;
}