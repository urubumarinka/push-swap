/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:55:03 by maborges          #+#    #+#             */
/*   Updated: 2025/06/06 14:44:43 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	algo_three(t_stack_node **stack_a)
{
	t_stack_node	*biggest;

	biggest = find_max(*stack_a);
	if (biggest == *stack_a)
		ra(stack_a, false);
	else if ((*stack_a)->next == biggest)
		rra(stack_a, false);
	if ((*stack_a)->num > (*stack_a)->next->num)
		sa(stack_a, false);
}
