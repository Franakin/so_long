/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:51:03 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 14:51:04 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && len > i)
	{
		k = 0;
		while (haystack[k + i] == needle[k] && len > (k + i))
		{
			k++;
			if (needle[k] == 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
