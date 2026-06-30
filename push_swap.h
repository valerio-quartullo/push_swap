/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:21:56 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/30 14:47:45 by vquartul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define ALGO_SIMPLE 0
# define ALGO_MEDIUM 1
# define ALGO_COMPLEX 2
# define ALGO_ADAPTIVE 3

typedef struct s_options
{
	int				strategy;
	int				bench;
	float			order;
	int				number;
}					t_options;

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}					t_node;

typedef struct s_count
{
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				sa;
	int				sb;
	int				rr;
	int				rrr;
	int				ss;
	int				tot;
}					t_count;

int					parse_flags(int argc, char **argv, t_options *opt);
void				error_exit(void);
int					*check_numbers(int argc, char **argv, int start);
int					is_duplicate(int *values, int count, int n);
void				assign_rank(t_node *a);
int					parse_numbers(int argc, char **argv, int start, t_node **a);
int					stack_size(t_node *a);
int					position_of_node(t_node *head, t_node *node);
void				move_to_top(t_node **a, int dist, int size,
						t_count *counter);
void				algo_simple(t_node **a, t_node **b, t_count *counter);
float				measure_disorder(t_node *a);
void				algo_medium(t_node **a, t_node **b, t_count *counter);
int					find_max_position(t_node *b);
void				push_a(t_node **a, t_node **b, t_count *counter);
void				push_b(t_node **a, t_node **b, t_count *counter);
void				swap_a(t_node **a, t_count *counter);
void				swap_b(t_node **b, t_count *counter);
void				rotate_a(t_node **a, t_count *counter);
void				rotate_b(t_node **b, t_count *counter);
void				rrotate_a(t_node **a, t_count *counter);
void				rrotate_b(t_node **b, t_count *counter);
t_node				*new_node(int content);
int					position_of_node(t_node *head, t_node *node);
int					atoi_check(const char *nptr);
void				print_stack(t_node *a);
void				algo_adaptive(t_node **a, t_node **b, t_count *counter,
						t_options *opt);

#endif
