/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:50:10 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 14:50:11 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *str, int c, size_t n)
{
	char	*pointer;

	pointer = str;
	while (n > 0)
	{
		*pointer = c;
		pointer++;
		n--;
	}
	return (str);
}
