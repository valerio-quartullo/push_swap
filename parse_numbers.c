/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:21:58 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/26 11:18:33 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(int *values, int count, int n)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (values[i] == n)
			return (1);
		i++;
	}
	return (0);
}

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

void	assign_rank(t_node *a)
{
	t_node	*current;
	t_node	*compare;
	int		new_rank;

	new_rank = 0;
	current = a;
	while (current)
	{
		compare = a;
		while (compare)
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

int	parse_numbers(int argc, char **argv, int start, t_node **a)
{
	int		i;
	t_node	*new;

	i = argc - 1;
	while (i >= start)
	{
		new = new_node(ft_atoi(argv[i]));
		if (!new)
			return (0);
		node_add_front(a, new);
		i--;
	}
	return (1);
}
