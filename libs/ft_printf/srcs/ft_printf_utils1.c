/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:02:43 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/09 10:45:49 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Print a character and return 1 */
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/* Print a string and return its length */
int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

/* Print an int and return its length */
int	ft_putnbr(int nb)
{
	long	n;
	int		len;

	len = 0;
	n = (long)nb;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else
		len += ft_putchar(n + 48);
	return (len);
}

/* Print an unsigned int and return its length */
int	ft_putunbr(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else
		len += ft_putchar(nb + 48);
	return (len);
}
