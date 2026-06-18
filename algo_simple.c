/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 09:36:27 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/18 15:47:26 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	algo_simple(int argc, t_node **a, t_node **b)
{
	t_node	*min;
	int	dist;
	int	i;
	int	count;

    count = 0;
	i = 0;
	min = find_min(*a);
	dist = position_of_node(*a, min);
	printf("numero piú piccolo = %d \n", find_min(*a)->value);
	printf("dist %d - %d\n", dist, argc / 2);
	if (dist < argc / 2)
	{
		while (i < dist - 1)
		{
			rrotate_a(a);
            count ++;
			i++;
		}
		push_b(a, b);
        count ++;
	}
	else
	{
		while (i < argc - dist -1)
		{
			rotate_a(a);
			count ++;
            i++;
		}
		push_b(a, b);
        count ++;
	}
	return (count);
}
