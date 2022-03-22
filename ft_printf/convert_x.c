/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_x.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:51:51 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 14:51:52 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	hex_converter(unsigned long i, int isitlower)
{
	unsigned int	remainder;
	int				total;

	total = 0;
	remainder = (i % 16);
	if (i > 15)
		total += hex_converter(i / 16, isitlower);
	if (remainder < 10)
		remainder += 48;
	else
		remainder = remainder + 55 + isitlower;
	ft_putchar_fd(remainder, 1);
	total++;
	return (total);
}

int	convert_x(unsigned long i, char c)
{
	int	total;
	int	isitlower;

	total = 0;
	if (c == 'x' || c == 'p')
		isitlower = 32;
	else
		isitlower = 0;
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		total += 2;
	}
	total += hex_converter(i, isitlower);
	return (total);
}
