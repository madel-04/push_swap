/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:45:04 by marvin            #+#    #+#             */
/*   Updated: 2024/11/12 10:45:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;

}				t_stack_node;

// *** CONTROL ERRORS ***
void			free_matrix(char **argv);
void			free_stack(t_stack_node **stack);
void			error_free(t_stack_node **a, char **argv, bool flag_argc_2);
int				error_syntax(char *str_nbr);
int				error_repetition(t_stack_node *a, int nbr);

// *** SPLIT ***
char			**ft_split(char *str, char sep);

// *** INIT ***
void			stack_init(t_stack_node **a, char **av, bool flag_ag_2);

// *** PS INIT ***
void			init_nodes(t_stack_node *a, t_stack_node *b);
void			set_current_position(t_stack_node *stack);
void			set_cheapest(t_stack_node *b);

// *** PUSH ***
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);

// *** REVERSE ROTATE ***
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);

// *** ROTATE BOTH ***
void			push_swap(t_stack_node **a, t_stack_node **b);
void			finish_rotation(t_stack_node **stack,
					t_stack_node *top_node,
					char stack_name);

// *** ROTATE ***
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);

// *** STACK UTILS ***
t_stack_node	*find_last_node(t_stack_node *head);
void			append_node(t_stack_node **stack, int nbr);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
int				stack_len(t_stack_node *stack);

// *** SWAP ***
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);

// *** THREE SORT ***
bool			stack_sorted(t_stack_node *stack);
void			three_sort(t_stack_node **a);
void			handle_five(t_stack_node **a, t_stack_node **b);

#endif