/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pushes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:49:12 by maborges          #+#    #+#             */
/*   Updated: 2025/06/25 13:07:25 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_node **src, t_node **dest)
{
	t_node	*to_push;

	if (!src || !(*src))
		return ;
	to_push = *src;
	*src = to_push->next;
	if (to_push->next)
		to_push->next->prev = NULL;
	to_push->next = *dest;
	if (*dest)
		(*dest)->prev = to_push;
	to_push->prev = NULL;
	*dest = to_push;
}

void	pa(t_node **stack_b, t_node**stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
