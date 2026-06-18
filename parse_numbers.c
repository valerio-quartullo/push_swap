/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:21:58 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/18 14:04:20 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_node	*new_node(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = content;
	node->next = NULL;
	return (node);
}

void	node_add_front(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	parse_numbers(int argc, char **argv, int start, t_node **a)
{
	int		i;
	int		j;
	t_node	*new;

	i = argc - 1;
	j = argc - start;
	while (i >= start)
	{
		new = new_node(ft_atoi(argv[i]));
		new->rank = j;
		j --;
		if (!new)
			return (0);
		node_add_front(a, new);
		i--;
	}
	return (1);
}
