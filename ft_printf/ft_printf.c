/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:46:54 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 14:46:55 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	check_convert(char c, va_list args)
{
	int		total;
	char	*str;

	if (c == 'd' || c == 'i')
		total = convert_d(va_arg(args, int));
	else if (c == 'p')
		total = convert_x(va_arg(args, unsigned long), c);
	else if (c == 'x' || c == 'X')
		total = convert_x(va_arg(args, unsigned int), c);
	else if (c == 'u')
		total = convert_u(va_arg(args, unsigned int));
	else if (c == '%')
		total = ft_putchar_fd(c, 1);
	else if (c == 'c')
		total = ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			return (write(1, "(null)", 6));
		total = ft_putstr_fd(str, 1);
	}
	else
		return (-1);
	return (total);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		total;

	va_start(args, str);
	total = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			total += check_convert(*str, args);
			if (total < 0)
				return (total);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			total++;
		}
		str++;
	}
	return (total);
}
