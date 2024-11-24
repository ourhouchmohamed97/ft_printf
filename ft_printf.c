/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:49:46 by mourhouc          #+#    #+#             */
/*   Updated: 2024/11/24 15:38:21 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion(va_list args, char *format, int *count)
{
	int	lower;

	lower = 0;
	if (*format == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (*format == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (*format == 'p')
	{
		write(1, "0x", 2);
		(*count) += 2;
		ft_putaddr(va_arg(args, void *), count);
	}
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (*format == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), count);
	else if (*format == 'x' || *format == 'X')
	{
		if (*format == 'x')
			lower = 1;
		ft_puthexa(va_arg(args, int), count, lower);
	}
	else if (*format == '%')
		ft_putchar('%', count);
}


int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	if (!format || write(1, NULL, 0) < 0)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_conversion(args, (char *)format, &count);
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
