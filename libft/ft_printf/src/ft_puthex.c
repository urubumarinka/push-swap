/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:57:40 by maborges          #+#    #+#             */
/*   Updated: 2025/01/27 17:32:01 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int hex)
{
	char	*hexdigits;
	int		count;
	int		re;

	count = 0;
	hexdigits = "0123456789ABCDEF";
	if (hex < 16)
	{
		re = ft_putchar(hexdigits[hex]);
		if (re == -1)
			return (-1);
		count += re;
	}
	else
	{
		re = ft_puthex(hex / 16);
		if (re == -1)
			return (-1);
		count += re;
		re = ft_puthex(hex % 16);
		if (re == -1)
			return (-1);
		count += re;
	}
	return (count);
}
