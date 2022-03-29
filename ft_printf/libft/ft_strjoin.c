/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:50:46 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/03/03 15:37:47 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*ret;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	while (*s1)
	{
		ret[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		ret[i] = *s2;
		i++;
		s2++;
	}
	ret[i] = 0;
	return (ret);
}
