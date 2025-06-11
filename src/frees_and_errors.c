/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:38:11 by maborges          #+#    #+#             */
/*   Updated: 2025/06/11 21:53:35 by maborges         ###   ########.fr       */
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
	//here write how to take a linked_list and free each node;
}
