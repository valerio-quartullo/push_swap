/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 10:50:16 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/30 11:42:10 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	find_max_position(t_node *b)
{
	int	max_val;
	int	max_pos;
	int	pos;

	max_val = b->value;
	max_pos = 0;
	pos = 0;
	while (b)
	{
		if (b->value > max_val)
		{
			max_val = b->value;
			max_pos = pos;
		}
		b = b->next;
		pos++;
	}
	return (max_pos);
}

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

void	move_to_top(t_node **a, int dist, int size, t_count *counter)
{
	if (dist <= size / 2)
	{
		while (dist > 0)
		{
			rotate_a(a, counter);
			dist--;
		}
	}
	else
	{
		while (dist < size)
		{
			rrotate_a(a, counter);
			dist++;
		}
	}
}
