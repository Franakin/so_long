/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:50:20 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 14:50:21 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_neg(int n, int fd)
{
	int	pol;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		pol = -1;
	}
	else
		pol = 1;
	return (pol);
}

static	void	do_math(int n, int len, int fd)
{
	int	i;
	int	div;
	int	pol;

	i = 0;
	div = 1;
	pol = check_neg(n, fd);
	while ((len - 1) > 0)
	{
		div *= 10;
		len--;
	}
	while (div >= 1)
	{
		ft_putchar_fd((((n / div) * pol) + '0'), fd);
		n %= div;
		div /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	len;
	int	n_cpy;

	len = 0;
	n_cpy = n;
	while (n_cpy != 0)
	{
		len++;
		n_cpy /= 10;
	}
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	do_math(n, len, fd);
}
