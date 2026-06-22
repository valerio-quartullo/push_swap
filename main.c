/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:29:05 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/22 11:57:01 by vquartul         ###   ########.fr       */
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
	if (opt.bench)
		printf("Disorder: %.2f%%\n", measure_disorder(a));
	if (!measure_disorder(a))
		return (0);
	print_stack(a);
	// algo_simple(argc - start, a, b);
	printf("Operations: %d\n\n", algo_simple(&a, &b));
	print_stack(a);
	write(1, "\n", 1);
	print_stack(b);
	return (0);
}
