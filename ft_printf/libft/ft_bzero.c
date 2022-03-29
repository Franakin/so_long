/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:48:06 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 14:48:07 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	char	*pointer;

	pointer = str;
	while (n)
	{
		*pointer = 0;
		pointer++;
		n--;
	}
}
