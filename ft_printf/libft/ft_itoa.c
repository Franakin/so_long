/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:49:15 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 14:49:16 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	check_neg(int n, int i, char *ret)
{
	int	pol;

	if (n < 0)
	{
		ret[i] = '-';
		pol = -1;
	}
	else
		pol = 1;
	return (pol);
}

static	void	do_math(char *ret, int n, int len)
{
	int	i;
	int	div;
	int	pol;

	i = 0;
	div = 1;
	pol = check_neg(n, i, ret);
	if (pol == -1)
		i++;
	while ((len - 1) > 0)
	{
		div *= 10;
		len--;
	}
	while (div >= 1)
	{
		ret[i] = ((n / div) * pol) + '0';
		n %= div;
		div /= 10;
		i++;
	}
	ret[i] = 0;
}

char	*ft_itoa(int n)
{
	int		len;
	int		n_cpy;
	int		if_neg;
	char	*ret;

	len = 0;
	n_cpy = n;
	if_neg = 0;
	while (n_cpy != 0)
	{
		len++;
		n_cpy /= 10;
	}
	if (n == 0)
		len++;
	if (n < 0)
		if_neg = 1;
	ret = (char *)malloc(sizeof(char) * (len + 1 + if_neg));
	if (!ret)
		return (NULL);
	do_math(ret, n, len);
	return (ret);
}
