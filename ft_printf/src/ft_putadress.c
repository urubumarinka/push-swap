/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:05:06 by maborges          #+#    #+#             */
/*   Updated: 2025/01/27 17:46:23 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	puthex(unsigned long nbr)
{
	char	*hexdigits;
	int		count;
	int		ret;

	count = 0;
	hexdigits = "0123456789abcdef";
	if (nbr < 16)
	{
		ret = write(1, &hexdigits[nbr], 1);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	else
	{
		ret = puthex(nbr / 16);
		if (ret == -1)
			return (-1);
		count += ret;
		ret = puthex(nbr % 16);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	return (count);
}

int	ft_putadress(void *pointer)
{
	int				count;
	int				ret;
	unsigned long	n;

	count = 0;
	if (pointer == NULL)
		return (write(1, "(nil)", 5));
	ret = write(1, "0x", 2);
	if (ret == -1)
		return (-1);
	count += ret;
	n = (unsigned long)pointer;
	ret = puthex(n);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
