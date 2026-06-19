/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 09:36:27 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/19 10:44:19 by marvin           ###   ########.fr       */
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

void	assign_rank(t_node *a)
{
	t_node	*current;
	t_node	*compare;
	int		new_rank;

	new_rank = 0;
	current = a;
	while(current)
	{
		compare = a;
		while(compare)
		{
			if (current->value > compare->value)
				new_rank++;
			compare = compare->next;
		}
		current->rank = new_rank;
		current = current->next;
		new_rank = 0;
	}
	return ;
}

int	algo_simple(int argc, t_node *a, t_node *b)
{
	int	dist;
	int	i;
	int	count;

    count = 0;
	i = 0;
	dist = find_min(a)->rank;
	printf("numero piú piccolo = %d \n", find_min(a)->value);
	printf("dist %d - %d\n", dist, argc / 2);
	if (dist < argc / 2)
	{
		while (i < dist - 1)
		{
			rrotate_a(&a);
            count ++;
			i++;
		}
		push_b(&a, &b);
        count ++;
	}
	else
	{
		while (i < dist - 1)
		{
			rotate_a(&a);
			count ++;
            i++;
		}
		push_b(&a, &b);
        count ++;
	}
	return (count);
}
