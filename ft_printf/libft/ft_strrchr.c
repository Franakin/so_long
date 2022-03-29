/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:51:07 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/01/18 14:51:08 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	if (!ft_isascii((char)c))
		return (NULL);
	i = ft_strlen(str);
	while (str[i] != (char)c && i > 0)
		i--;
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}
