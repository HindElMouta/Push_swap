/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:28:41 by hinel-mo          #+#    #+#             */
/*   Updated: 2025/03/25 15:28:41 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_min_to_b(t_stack **a, t_stack **b)
{
	int lowest_pos = get_lowest_index_position(a);
	int size = get_stack_size(*a);

	if (lowest_pos <= size / 2)
	{
		while (lowest_pos-- > 0)
			do_ra(a);
	}
	else
	{
		while (lowest_pos++ < size)
			do_rra(a);
	}
	do_pb(a, b);
}

void small_sort(t_stack **a, t_stack **b)
{
	int size = get_stack_size(*a);

	if (size == 4)
	{
		push_min_to_b(a, b);
		tiny_sort(a);
		do_pa(a, b);
	}
	else if (size == 5)
	{
		push_min_to_b(a, b);
		push_min_to_b(a, b);
		tiny_sort(a);
		do_pa(a, b);
		do_pa(a, b);
		if ((*a)->index > (*a)->next->index)
			do_sa(a);
	}
}
