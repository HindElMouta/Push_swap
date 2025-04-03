/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:48:30 by hinel-mo          #+#    #+#             */
/*   Updated: 2025/04/03 14:53:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_argc(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**handle_split_args(char **av, int *free_args)
{
	char	**args;

	args = ft_split(av[1], ' ');
	if (!args || !args[0])
		exit_error(NULL, NULL);
	*free_args = 1;
	return (args);
}

static void	push_swap(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && !is_sorted(*a))
		do_sa(a);
	else if (size == 3)
		tiny_sort(a);
	else if ((size == 4 || size == 5) && !is_sorted(*a))
		small_sort(a, b);
	else if (size > 5 && !is_sorted(*a))
		sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		stack_size;
	int		free_args;

	if (ac < 2)
		return (0);
	if (ac == 2)
		args = handle_split_args(av, &free_args);
	else
	{
		args = &av[1];
		free_args = 0;
	}
	if (!is_correct_input(args))
		exit_error(NULL, NULL);
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
	return (0);
}
