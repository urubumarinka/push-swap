/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:05:22 by maborges          #+#    #+#             */
/*   Updated: 2025/01/27 17:30:17 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_puthex_min(unsigned int hex)
{
	char	*hexdigits;
	int		count;
	int		re;

	count = 0;
	hexdigits = "0123456789abcdef";
	if (hex < 16)
	{
		re = ft_putchar(hexdigits[hex]);
		if (re == -1)
			return (-1);
		count += re;
	}
	else
	{
		re = ft_puthex_min(hex / 16);
		if (re == -1)
			return (-1);
		count += re;
		re = ft_puthex_min(hex % 16);
		if (re == -1)
			return (-1);
		count += re;
	}
	return (count);
}
