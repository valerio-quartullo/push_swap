/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 12:00:36 by marvin            #+#    #+#             */
/*   Updated: 2026/06/19 12:00:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *a)
{
	int	size;

	size = 0;
	while (a)
	{
		a = a->next;
		size++;
	}
	return (size);
}

int	position_of_node(t_node *head, t_node *node)
{
	int	pos;

	pos = 0;
	while (head)
	{
		if (head == node)
			return (pos);
		head = head->next;
		pos++;
	}
	return (-1);
}

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

static void	extract_min(t_node **a, t_node **b, int *count)
{
	t_node	*min;
	int		dist;
	int		size;

	size = stack_size(*a);
	min = find_min(*a);
	dist = position_of_node(*a, min);
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