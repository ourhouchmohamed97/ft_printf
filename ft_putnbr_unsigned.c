/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:10:27 by mourhouc          #+#    #+#             */
/*   Updated: 2024/11/23 16:41:06 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n, int *counter)
{
	char	digit;

	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, counter);
		ft_putnbr_unsigned(n % 10, counter);
	}
	else
	{
		digit = n + 48;
		write (1, &digit, 1);
		(*counter)++;
	}
}
