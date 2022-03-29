/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:49:57 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 14:49:58 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;

	str = (const char *)s;
	if (n == 0)
		return (NULL);
	while (n > 0)
	{
		n--;
		if (*str == (char)c)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
