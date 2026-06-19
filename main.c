/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:29:05 by vquartul          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/06/19 10:44:19 by marvin           ###   ########.fr       */
=======
/*   Updated: 2026/06/18 15:45:34 by vquartul         ###   ########.fr       */
>>>>>>> f3f32cb79fed2867d3337c700441bcd5aadde790
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// PROVA DI STAMPA
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
	assign_rank(a);
	print_stack(a);
	// algo_simple(argc - start, a, b);
	printf("%d\n\n", algo_simple(argc, &a, &b));
	print_stack(a);
	write(1, "\n", 1);
	print_stack(b);
	return (0);
}
