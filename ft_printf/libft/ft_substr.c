/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:51:18 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 14:51:19 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		return (ft_strdup(s + start));
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (len > 0 && s && start < (ft_strlen(s) + 1))
	{
		sub[i] = s[start];
		i++;
		start++;
		len--;
	}
	sub[i] = 0;
	return (sub);
}
