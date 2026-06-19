/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:37:08 by marvin            #+#    #+#             */
/*   Updated: 2026/06/18 16:37:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_b(t_node **b, int *count)
{
	t_node *first;
	t_node *tmp;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	*b = (*b)->next;
	tmp = *b;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
	(*count)++;
}