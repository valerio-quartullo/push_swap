/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:14:30 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/24 16:02:28 by vquartul         ###   ########.fr       */
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

static t_node	*find_best_in_chunk(t_node *a, t_node *b, int max_rank,
		int size_a, int size_b)
{
	t_node	*best;
	t_node	*tmp;
	int		best_cost;
	int		pos_a;
	int		cost_a;
	int		cost_b;
	int		pos;

	best = NULL;
	best_cost = size_a + size_b + 1;
	tmp = a;
	pos = 0;
	while (tmp)
	{
		if (tmp->rank < max_rank)
		{
			pos_a = pos;
			cost_a = pos_a;
			if (cost_a > size_a / 2)
				cost_a = size_a - cost_a;
			cost_b = find_insert_position(b, tmp->value);
			if (cost_b > size_b / 2)
				cost_b = size_b - cost_b;
			if (cost_a + cost_b < best_cost)
			{
				best = tmp;
				best_cost = cost_a + cost_b;
			}
		}
		tmp = tmp->next;
		pos++;
	}
	return (best);
}

static int	extract_from_chunk(t_node **a, t_node **b, int *count,
		int current_chunk, int chunk_size)
{
	t_node	*target;
	int		dist;
	int		size_a;
	int		size_b;
	int		max_rank;

	max_rank = (current_chunk + 1) * chunk_size;
	size_a = stack_size(*a);
	size_b = stack_size(*b);
	target = find_best_in_chunk(*a, *b, max_rank, size_a, size_b);
	if (!target)
		return (0);
	dist = position_of_node(*a, target);
	move_to_top(a, dist, size_a, count);
	insert_into_b(a, b, count);
	return (1);
}

int	algo_medium(t_node **a, t_node **b)
{
	int	count;
	int	size;
	int	chunk_size;
	int	current_chunk;
	int	num_chunks;
	int	max_pos;
	int	size_b;

	count = 0;
	size = stack_size(*a);
	num_chunks = int_sqrt(size);
	if (num_chunks <= 0)
		num_chunks = 1;
	chunk_size = size / num_chunks + 1;
	current_chunk = 0;
	while (*a)
	{
		if (!extract_from_chunk(a, b, &count, current_chunk, chunk_size))
			current_chunk++;
	}
	while (*b)
	{
		max_pos = find_max_position(*b);
		size_b = stack_size(*b);
		if (max_pos <= size_b / 2)
		{
			while (max_pos > 0)
			{
				rotate_b(b, &count);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < size_b)
			{
				rrotate_b(b, &count);
				max_pos++;
			}
		}
		push_a(a, b, &count);
	}
	return (count);
}
