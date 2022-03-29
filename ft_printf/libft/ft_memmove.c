/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:50:07 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 14:50:08 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*point2dest;
	unsigned char	*point2src;

	point2dest = (unsigned char *)dest;
	point2src = (unsigned char *)src;
	if (!n || dest == src)
		return (dest);
	if (point2dest > point2src)
	{
		while (n)
		{
			n--;
			point2dest[n] = point2src[n];
		}
	}
	else
	{
		while (n)
		{
			n--;
			*point2dest++ = *point2src++;
		}
	}
	return (dest);
}
