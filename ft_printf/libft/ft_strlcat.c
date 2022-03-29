/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:50:48 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 14:50:49 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	total;
	size_t	dstsizecpy;

	dstsizecpy = dstsize;
	total = ft_strlen(dst) + ft_strlen(src);
	while (*dst && dstsize > 0)
	{
		dstsize--;
		dst++;
	}
	if (dstsize == 0)
		return (ft_strlen(src) + dstsizecpy);
	while (*src && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = 0;
	return (total);
}
