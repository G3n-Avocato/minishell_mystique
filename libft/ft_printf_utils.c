/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:10:33 by lamasson          #+#    #+#             */
/*   Updated: 2022/11/21 20:24:59 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_rec(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_rec(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		size++;
	}
	if (n > 9)
	{
		size += ft_putnbr_rec(n / 10);
		size += ft_putnbr_rec(n % 10);
	}
	if (n < 10)
		size += ft_putchar_rec(n + 48);
	return (size);
}

int	ft_putstr_rec(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(unsigned long long n, char *base)
{
	unsigned int	base_size;
	int				size;

	base_size = ft_strlen(base);
	size = 0;
	if (n >= base_size)
	{
		size += ft_putnbr_base(n / base_size, base);
		size += ft_putnbr_base(n % base_size, base);
	}
	if (n < base_size)
	{
		size += ft_putchar_rec(base[n]);
	}
	return (size);
}
