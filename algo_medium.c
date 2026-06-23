/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:14:30 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/23 12:49:18 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_min_in_chunk(t_node *a, int max_rank)
{
	t_node	*min;

	min = NULL;
	while (a)
	{
		if (a->rank < max_rank)
		{
			if (!min || a->rank < min->rank)
				min = a;
		}
		a = a->next;
	}
	return (min);
}

static int	extract_from_chunk(t_node **a, t_node **b, int *count,
		int current_chunk, int chunk_size)
{
	t_node	*target;
	int		dist;
	int		size;
	int		max_rank;

	max_rank = (current_chunk + 1) * chunk_size;
	target = find_min_in_chunk(*a, max_rank);
	if (!target)
		return (0);
	size = stack_size(*a);
	dist = position_of_node(*a, target);
	move_to_top(a, dist, size, count);
	push_b(a, b, count);
	return (1);
}

static int	int_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
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