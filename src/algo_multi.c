/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:52:14 by maborges          #+#    #+#             */
/*   Updated: 2025/06/24 22:40:50 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_a2b(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest_a;


	cheapest_a = get_cheapest(*stack_a);
	if (cheapest_a->above_median && cheapest_a->target_node->above_median)
		rr(stack_a, stack_b, cheapest_a);
	else if (!(cheapest_a->above_median)
		&& !(cheapest_a->target_node->above_median))
		rrr(stack_a, stack_b, cheapest_a);
	set_top (stack_a, cheapest_a, 'a');
	set_top(stack_b, cheapest_a->target_node, 'b');
	pb(cheapest_a, cheapest_a->target_node);
}

void	algo_multi(t_node **stack_a, t_node **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !stack_sorted(stack_a))
		pb(stack_b, stack_a);
	if (len_a-- > 3 && !stack_sorted(stack_a))
		pb(stack_b, stack_a);
	while (len_a-- > 3 && !stack_sorted(stack_a))
	{
		prepare_node_a(*stack_a, *stack_b);
		push_a2b(stack_a, stack_b);
	}
	algo_three(*stack_a);
	while (*stack_b)
	{
		prepare_node_b(*stack_a, *stack_b); //to do
		push_b2a(stack_a, stack_b); // to do
	}
	get_index_median(*stack_a);
	//check if min is on top
}

