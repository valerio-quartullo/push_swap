/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:14:30 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/24 14:54:00 by vquartul         ###   ########.fr       */
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

static t_node	*find_closest_in_chunk(t_node *a, int max_rank, int size)
{
	t_node	*best;
	t_node	*tmp;
	int		best_dist;
	int		pos;
	int		dist;

	best = NULL;
	best_dist = size + 1;
	tmp = a;
	pos = 0;
	while (tmp)
	{
		if (tmp->rank < max_rank)
		{
			dist = pos;
			if (dist > size / 2)
				dist = size - dist;
			if (dist < best_dist)
			{
				best = tmp;
				best_dist = dist;
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
	int		size;
	int		max_rank;

	max_rank = (current_chunk + 1) * chunk_size;
	while(max_rank > 0)
	{	
		size = stack_size(*a);
		target = find_closest_in_chunk(*a, max_rank, size);
		if (!target)
			return (0);
		dist = position_of_node(*a, target);
		move_to_top(a, dist, size, count);
		insert_into_b(a, b, count);
		printf("--- A ---\n");
		print_stack(*a);
		printf("--- B ---\n");
		print_stack(*b);
	}
	return (1);
}

int	algo_medium(t_node **a, t_node **b)
{
	int	count;
	int	size;
	int	chunk_size;
	int	current_chunk;
	int	num_chunks;

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
		push_a(a, b, &count);
	return (count);
}
