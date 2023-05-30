/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:27:41 by lamasson          #+#    #+#             */
/*   Updated: 2022/11/18 16:12:27 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_add_p(va_list ap)
{
	unsigned long long	tmp;
	int					size;

	size = 0;
	tmp = va_arg(ap, unsigned long long);
	if (!tmp)
		size = ft_putstr_rec("(nil)");
	else
	{
		size = ft_putstr_rec("0x");
		size += ft_putnbr_base(tmp, "0123456789abcdef");
	}
	return (size);
}

static int	ft_others(char c)
{
	int	size;

	size = 0;
	size = ft_putchar_rec('%');
	size += ft_putchar_rec(c);
	return (size);
}

static int	ft_find_arg(const char c, va_list ap)
{
	int	size;

	size = 0;
	if (c == 'c')
		size = ft_putchar_rec(va_arg(ap, int));
	else if (c == 's')
		size = ft_putstr_rec(va_arg(ap, char *));
	else if (c == 'p')
		size = ft_add_p(ap);
	else if (c == 'd')
		size = ft_putnbr_rec(va_arg(ap, int));
	else if (c == 'i')
		size = ft_putnbr_rec(va_arg(ap, int));
	else if (c == 'u')
		size = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (c == 'x')
		size = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		size = ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		size = ft_putchar_rec('%');
	else
		size = ft_others(c);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (str == NULL)
		return (-1);
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			size += ft_find_arg(str[i + 1], ap);
			i += 2;
		}
		else
		{
			size += ft_putchar_rec(str[i]);
			i++;
		}
	}
	va_end(ap);
	return (size);
}
