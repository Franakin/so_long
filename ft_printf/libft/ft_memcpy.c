/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:50:05 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 14:50:06 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pointer;

	if (!n || dest == src)
		return (dest);
	pointer = (unsigned char *)dest;
	while (n)
	{
		*pointer++ = *((unsigned char *)src++);
		n--;
	}
	return (dest);
}
