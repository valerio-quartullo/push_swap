/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:53:42 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/24 16:56:46 by vquartul         ###   ########.fr       */
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

int	find_max_position(t_node *b)
{
    int max_val = b->value;
    int max_pos = 0;
    int pos = 0;
    
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