/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:25:03 by maborges          #+#    #+#             */
/*   Updated: 2025/05/21 17:17:47 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# include "../../libft.h"

int			ft_printf(const char *__format, ...);
int			ft_putnbr(int n);
int			ft_putnbr_unsigned(unsigned int n);
int			ft_putstr(char *s);
int			ft_putadress(void *pointer);
int			ft_puthex_min(unsigned int hex);
int			ft_puthex(unsigned int hex);
int			ft_putchar(char c);

#endif
