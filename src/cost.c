/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:49:54 by hinel-mo          #+#    #+#             */
/*   Updated: 2025/02/12 17:49:54 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_cost(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_b;
    int size_a;
    int size_b;

    if (!stack_a || !stack_b)
        return;

    size_a = get_stack_size(*stack_a);
    size_b = get_stack_size(*stack_b);
    tmp_b = *stack_b;

    while (tmp_b)
    {
        tmp_b->cost_b = tmp_b->pos;
        if (tmp_b->pos > size_b / 2)
            tmp_b->cost_b = (size_b - tmp_b->pos) * -1;

        tmp_b->cost_a = tmp_b->target_pos;
        if (tmp_b->target_pos > size_a / 2)
            tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;

        tmp_b = tmp_b->next;
    }
}

void do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    int cheapest;
    int cost_a = 0;
    int cost_b = 0;
    int current_cost;

    if (!stack_a || !stack_b || !*stack_b)
        return;

    tmp = *stack_b;
    cheapest = INT_MAX;

    while (tmp)
    {
        current_cost = nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b);
		if (current_cost < cheapest)
        {
            cheapest = current_cost;
            cost_a = tmp->cost_a;
            cost_b = tmp->cost_b;
        }
        tmp = tmp->next;
    }

    do_move(stack_a, stack_b, cost_a, cost_b);
}
