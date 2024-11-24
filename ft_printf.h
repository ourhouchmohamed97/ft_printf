/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourhouc <mourhouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:52:48 by mourhouc          #+#    #+#             */
/*   Updated: 2024/11/24 12:58:17 by mourhouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putnbr(int n, int *counter);
void	ft_putsign(int n, int *counter);
void	ft_putchar(char c, int *counter);
void	ft_putstr(char *s, int *counter);
void	ft_putaddr(void *ptr, int *counter);
void	ft_puthexa(int n, int *counter, int lower);
void	ft_putnbr_unsigned(unsigned int n, int *counter);
#endif