/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:05:52 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/18 12:09:38 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_node **a)
{
	t_node *first;
	t_node *tmp;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}