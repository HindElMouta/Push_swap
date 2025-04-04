/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:48:30 by hinel-mo          #+#    #+#             */
/*   Updated: 2025/04/04 11:09:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_args(int ac, char **av, char ***args, int *free_args)
{
	if (ac == 2)
		*args = handle_split_args(av, free_args);
	else
	{
		*args = &av[1];
		*free_args = 0;
	}
	if (!is_correct_input(*args))
		exit_error(NULL, NULL);
}

static void	start_push_swap(char **args, int free_args)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_b = NULL;
	stack_a = fill_stack_values(get_argc(args), args);
	if (!stack_a)
		exit_error(NULL, NULL);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (free_args)
		free_split(args);
}

int	main(int ac, char **av)
{
	char	**args;
	int		free_args;

	if (ac < 2)
		return (0);
	init_args(ac, av, &args, &free_args);
	start_push_swap(args, free_args);
	return (0);
}
