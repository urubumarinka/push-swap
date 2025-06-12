/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:42:54 by maborges          #+#    #+#             */
/*   Updated: 2025/06/12 17:15:33 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/inc/ft_printf.h"
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // take it out at the end
# include <stdbool.h> // check if I use bool flags or 0 1 flags

//Data holding struct for stacks

typedef struct s_node
{
	int						num;
	int						index;
	int						cost;
	bool					above_median;
	bool					cheapest;
	struct s_node			*target_node;
	struct s_node			*next;
	struct s_node			*prev;
}	t_node;

//Error Handlers
void			error_msg(void);
void			free_and_error(t_node **stack);
void			free_stack(t_node **stack);

//stack
char			**split(char *s, char c);
void			init_stack_a(t_node **stack_a, char **av);

//Nodes init

//Utils

t_node			*find_max(t_node *stack);
char			*ft_strchr(const char *s, int c);

//Commands

//Algorithm

#endif
