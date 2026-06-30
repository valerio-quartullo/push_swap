/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:29:05 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/30 14:28:25 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *a)
{
	while (a)
	{
		printf("%d / ", a->value);
		a = a->next;
	}
}

void	init_counter(t_count *counter)
{
	counter->pa = 0;
	counter->pb = 0;
	counter->ra = 0;
	counter->rb = 0;
	counter->rra = 0;
	counter->rrb = 0;
	counter->sa = 0;
	counter->sb = 0;
	counter->rr = 0;
	counter->rrr = 0;
	counter->ss = 0;
	counter->tot = 0;
}

static int	init_and_parse(int argc, char **argv, t_options *opt,
		t_node **a, t_count *counter)
{
	int	start;
	int	*values;

	init_counter(counter);
	opt->strategy = ALGO_ADAPTIVE;
	opt->bench = 0;
	start = parse_flags(argc, argv, opt);
	if (start >= argc)
		return (-1);
	values = check_numbers(argc, argv, start);
	if (!values)
		error_exit();
	free(values);
	parse_numbers(argc, argv, start, a);
	assign_rank(*a);
	return (start);
}

static void	run_algorithm(t_node **a, t_node **b, t_options *opt,
		t_count *counter)
{
	if (opt->strategy == ALGO_SIMPLE)
	{
		algo_simple(a, b, counter);
		printf("algo_simple operations: %d, %d, %d, %d, %d\n\n", counter->tot, counter->rra, counter->pb, counter->sa, counter->rr);
	}
	if (opt->strategy == ALGO_MEDIUM)
	{
		algo_medium(a, b, counter);
		printf("algo_medium operations: %d, %d, %d, %d, %d\n\n", counter->tot, counter->rra, counter->pb, counter->sa, counter->rr);
	}
}

int	main(int argc, char **argv)
{
	t_options	opt;
	t_node		*a;
	t_node		*b;
	t_count		counter;
	int			start;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	start = init_and_parse(argc, argv, &opt, &a, &counter);
	if (start < 0)
		return (0);
	opt.order = measure_disorder(a);
	opt.number = argc - start;
	if (opt.bench)
		printf("Disorder: %.2f%%\n", opt.order);
	if (!measure_disorder(a))
		return (0);
	if (opt.strategy == ALGO_ADAPTIVE)
		algo_adaptive(&a, &b, &counter, &opt);
	else
		run_algorithm(&a, &b, &opt, &counter);
	return (0);
}

