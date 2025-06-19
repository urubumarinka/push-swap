/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:38:11 by maborges          #+#    #+#             */
/*   Updated: 2025/06/19 14:56:42 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_and_error(t_node **stack)
{
	free_stack(stack);
	write(2, "stackfreed\n", 11); // take this out at the end
	error_msg();
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		//printf("Freeing node with num: %d\n", (*stack)->num);
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
