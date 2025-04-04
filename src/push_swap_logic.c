/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:03:56 by marvin            #+#    #+#             */
/*   Updated: 2025/04/04 11:03:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b, int size)
{
	if (is_sorted(*a))
		return ;
	if (size == 2)
		do_sa(a);
	else if (size == 3)
		tiny_sort(a);
	else if (size == 4 || size == 5)
		small_sort(a, b);
	else if (size > 5)
		sort(a, b);
}
