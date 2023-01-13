/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:14:34 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/09 10:45:32 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Print an unsigned int in hexadecimal and return its length */
int	ft_putnbr_base(unsigned long nb, char *base)
{
	int	res;

	res = 0;
	if (nb >= 16)
		res += ft_putnbr_base(nb / 16, base);
	res += ft_putchar(base[nb % 16]);
	return (res);
}

/* Print the address of a pointer in hexadecimal */
int	ft_putptr(unsigned long nb)
{
	int	res;

	write(1, "0x", 2);
	res = ft_putnbr_base(nb, HEXA_LOWER);
	return (res + 2);
}
