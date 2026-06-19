/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:52:04 by marvin            #+#    #+#             */
/*   Updated: 2026/06/18 15:52:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
void    swap_a(t_node **a)
{
    int  value_temp;
    int  rank_temp;

    if (!*a ||!(*a)->next)
    return ;
    value_temp = (*a)->next->value;
    rank_temp = (*a)->next->rank;
    (*a)->next->value = (*a)->value;
    (*a)->next->rank = (*a)->rank;
    (*a)->value = value_temp;
    (*a)->rank = rank_temp;
    write(1, "sa\n", 3);
    return ;
}