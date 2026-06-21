/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:21:56 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/19 11:27:37 by marvin           ###   ########.fr       */
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
}					t_options;

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}					t_node;

int					parse_flags(int argc, char **argv, t_options *opt);
void				error_exit(void);
int	*check_numbers(int argc, char **argv, int start);
void				assign_rank(t_node *a);
int					parse_numbers(int argc, char **argv, int start, t_node **a);
int					algo_simple(t_node **a, t_node **b);

/* operazioni base */
void				push_a(t_node **a, t_node **b, int *count);
void				push_b(t_node **a, t_node **b, int *count);
void				swap_a(t_node **a, int *count);
void				swap_b(t_node **b, int *count);
void				rotate_a(t_node **a, int *count);
void				rotate_b(t_node **b, int *count);
void				rrotate_a(t_node **a, int *count);
void				rrotate_b(t_node **b, int *count);

t_node				*new_node(int content);
int					position_of_node(t_node *head, t_node *node);
int					atoi_check(const char *nptr);

#endif