/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_du.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:51:46 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 14:51:47 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	convert_d(int i)
{
	int	total;
	int	polarity;

	total = 0;
	polarity = 1;
	if (i < 0)
	{
		ft_putchar_fd('-', 1);
		polarity = -1;
		total++;
	}
	total += convert_u((unsigned int)(i * polarity));
	return (total);
}

int	convert_u(unsigned int i)
{
	unsigned int	remainder;
	int				total;

	total = 0;
	remainder = (i % 10);
	if (i > 9)
		total += convert_u(i / 10);
	ft_putchar_fd(remainder + 48, 1);
	total++;
	return (total);
}
