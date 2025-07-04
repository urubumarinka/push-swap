/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:25:05 by maborges          #+#    #+#             */
/*   Updated: 2025/01/27 14:29:04 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	count;
	int	re;

	i = 0;
	count = 0;
	re = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		re = write(1, &s[i], 1);
		if (re == -1)
			return (-1);
		i++;
		count++;
	}
	return (count);
}
