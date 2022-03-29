/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:47:58 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 14:47:59 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	ret;
	int	pol;

	ret = 0;
	pol = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			pol = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + (*str - '0') * pol;
		str++;
	}
	return (ret);
}
