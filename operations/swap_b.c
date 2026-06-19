/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 16:04:31 by marvin            #+#    #+#             */
/*   Updated: 2026/06/18 16:04:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
void    swap_b(t_node **b)
{
    int  value_temp;
    int  rank_temp;

    if (!*b ||!(*b)->next)
    return ;
    value_temp = (*b)->next->value;
    rank_temp = (*b)->next->rank;
    (*b)->next->value = (*b)->value;
    (*b)->next->rank = (*b)->rank;
    (*b)->value = value_temp;
    (*b)->rank = rank_temp;
    write(1, "sb\n", 3);
    return ;
}