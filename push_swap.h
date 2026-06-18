/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquartul <vquartul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 12:21:56 by vquartul          #+#    #+#             */
/*   Updated: 2026/06/18 12:16:05 by vquartul         ###   ########.fr       */
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
int					parse_numbers(int argc, char **argv, int start, t_node **a);
int	algo_simple(int argc, t_node *a, t_node *b);
void	rotate_a(t_node **a);
void	rrotate_a(t_node **a);
void	push_b(t_node **a, t_node **b);

#endif