/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:53:42 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/24 11:22:59 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_insert_position(t_node *b, int value)
{
	int	pos;

	pos = 0;
	while (b && b->value > value)
	{
		b = b->next;
		pos++;
	}
	return (pos);
}

void	insert_into_b(t_node **a, t_node **b, int *count)
{
	int	size_b;
	int	pos;

	size_b = stack_size(*b);
	pos = find_insert_position(*b, (*a)->value);
	if (pos <= size_b / 2)
	{
		while (pos > 0)
		{
			rotate_b(b, count);
			pos--;
		}
	}
	else
	{
		while (pos < size_b)
		{
			rrotate_b(b, count);
			pos++;
		}
	}
	push_b(a, b, count);
}
