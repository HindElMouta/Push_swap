/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinel-mo <hinel-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:51:05 by hinel-mo          #+#    #+#             */
/*   Updated: 2025/04/03 16:41:58 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Initialization */
t_stack		*fill_stack_values(int ac, char **av);
void		assign_index(t_stack *stack_a, int ac);

/* Sorting Algorithms */
int			is_sorted(t_stack *stack);
void		tiny_sort(t_stack **stack);
void		small_sort(t_stack **a, t_stack **b);
void		sort(t_stack **stack_a, t_stack **stack_b);
void		push_swap(t_stack **a, t_stack **b, int size);

/* Position & Target */
int			get_lowest_index_position(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);

/* Cost & Moves */
void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* Stack Operations */
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);

/* Stack Utils */
t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack *stack);

/* General Utils */
void		free_stack(t_stack **stack);
void		ft_putstr(char *str);
long int	ft_atoi(const char *str);
int			nb_abs(int nb);
char		**ft_split(const char *str, char sep);
int			get_argc(char **args);
void		free_split(char **arr);

/* Input Parsing & Validation */
int			is_correct_input(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);
char		**handle_split_args(char **av, int *free_args);

/* Error */
void		exit_error(t_stack **stack_a, t_stack **stack_b);

# ifdef DEBUG

void		print_stack(t_stack *stack);

# endif

#endif
