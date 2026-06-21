/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:18:56 by marvin            #+#    #+#             */
/*   Updated: 2026/06/18 16:18:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_a(t_node **a, t_node **b, int *count)
{
	t_node	*moved;

	if (!*b)
		return ;
	moved = *b;
	*b = (*b)->next;
	moved->next = *a;
	*a = moved;
	write(1, "pa\n", 3);
	(*count)++;
}