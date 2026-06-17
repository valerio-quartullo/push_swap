/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:29:05 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/17 18:41:57 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//PROVA DI STAMPA
void	print_stack(t_node *a)
{
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	t_options	opt;
	t_node		*a;
	t_node		*b;
	int			start;

	if (argc == 1)
		return (0);
	opt.strategy = ALGO_ADAPTIVE;
	opt.bench = 0;
	start = parse_flags(argc, argv, &opt);
	if (start >= argc)
		return (0);
	a = NULL;
	b = NULL;
	parse_numbers(argc, argv, start, &a);
	print_stack(a);
	return (0);
}
