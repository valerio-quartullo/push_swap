/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 12:05:56 by marvin            #+#    #+#             */
/*   Updated: 2026/06/19 12:05:56 by marvin           ###   ########.fr       */
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
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_options	opt;
	t_node		*a;
	t_node		*b;
	int			start;
	int			*values;

	if (argc == 1)
		return (0);
	opt.strategy = ALGO_ADAPTIVE;
	opt.bench = 0;
	start = parse_flags(argc, argv, &opt);
	if (start >= argc)
		return (0);
	a = NULL;
	b = NULL;
	values = check_numbers(argc, argv, start);
	if (!values)
		error_exit();
	free(values);
	parse_numbers(argc, argv, start, &a);
	assign_rank(a);
	print_stack(a);
	printf("Number of operations: %d\n\n", algo_simple(&a, &b));
	write(1, "\n", 1);
	print_stack(a);
	return (0);
}
