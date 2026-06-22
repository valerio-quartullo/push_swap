/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 12:00:36 by marvin            #+#    #+#             */
/*   Updated: 2026/06/22 10:51:25 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_node *a)
{
	t_node	*min;

	min = a;
	while (a)
	{
		if (a->value < min->value)
			min = a;
		a = a->next;
	}
	return (min);
}

static void	move_to_top(t_node **a, int dist, int size, int *count)
{
	if (dist <= size / 2)
	{
		while (dist > 0)
		{
			rotate_a(a, count);
			dist--;
		}
	}
	else
	{
		while (dist < size)
		{
			rrotate_a(a, count);
			dist++;
		}
	}
}

static void	extract_min(t_node **a, t_node **b, int *count)
{
	t_node	*min;
	int		dist;
	int		size;

	size = stack_size(*a);
	min = find_min(*a);
	dist = position_of_node(*a, min);
	if (dist == 1)
		swap_a(a, count);
	else
		move_to_top(a, dist, size, count);
	push_b(a, b, count);
}

int	algo_simple(t_node **a, t_node **b)
{
	int	count;

	count = 0;
	while (*a)
		extract_min(a, b, &count);
	while (*b)
		push_a(a, b, &count);
	return (count);
}
