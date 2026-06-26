/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:14:30 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/26 12:47:14 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	move_to_top_b(t_node **b, int max_pos, int size_b, t_count *counter)
{
	if (max_pos <= size_b / 2)
	{
		while (max_pos > 0)
		{
			rotate_b(b, counter);
			max_pos--;
		}
	}
	else
	{
		while (max_pos < size_b)
		{
			rrotate_b(b, counter);
			max_pos++;
		}
	}
}

void	algo_medium(t_node **a, t_node **b, t_count *counter)
{
	int	size;
	int	num_chunks;
	int	chunk_limit;
	int i;
	
	size = stack_size(*a);
	num_chunks = int_sqrt(size);
	if (num_chunks <= 0)
		num_chunks = 1;
	chunk_limit = size / num_chunks;
	i = 0;
	while (*a)
	{
		if ((*a)->rank <= i)
		{
			push_b(a, b, counter);
			if (*b && (*b)->rank <= (i - chunk_limit / 2))
				rotate_b(b, counter);
			i++;
		}
		else if ((*a)->rank < i + chunk_limit)
		{
			push_b(a, b, counter);
			i++;
		}
		else
			rotate_a(a, counter);
	}
	while (*b)
	{
		move_to_top_b(b, find_max_position(*b), stack_size(*b), counter);
		push_a(a, b, counter);
	}
}
