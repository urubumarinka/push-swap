/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:36:04 by maborges          #+#    #+#             */
/*   Updated: 2025/01/24 17:11:47 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int		count;
	long	nb;
	int		re;

	count = 0;
	nb = n;
	if (nb >= 10)
	{
		re = ft_putnbr_unsigned(nb / 10);
		if (re == -1)
			return (-1);
		count += re;
	}
	re = ft_putchar((nb % 10) + '0');
	if (re == -1)
		return (-1);
	count += re;
	return (count);
}
