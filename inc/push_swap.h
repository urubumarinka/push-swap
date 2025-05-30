/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:42:54 by maborges          #+#    #+#             */
/*   Updated: 2025/05/30 12:20:59 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf/inc/ft_printf.h"
# include <limits.h>
# include <stdbool.h> // check if I use bool flags or 0 1 flags

//Data holding struct for stacks

typedef struct s_stack_node
{
	int						num;
	int						index;
	int						cost;
	bool					above_median;
	bool					cheapest;
	struct s_stack_node		*target_node;
	struct s_stack_node		*next;
	struct_s_stach_node		*prev;
}	t_stack_node;

//Error Handlers

//Stack init

//Nodes init

//Stack utils

//Commands

//Algorithm

#endif
