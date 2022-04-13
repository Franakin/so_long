/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:50:33 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/04/13 18:06:34 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c && *s)
			s++;
		else
		{
			while (*s != c && *s)
				s++;
			count++;
		}
	}
	return (count);
}

static	void	free_k(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static	void	write_split(char **strs, char const *s, char c, int wordcount)
{
	int	i;
	int	k;

	k = 0;
	while (k < wordcount)
	{
		i = 0;
		while (*s == c && *s)
			s++;
		while (s[i] != c && s[i])
			i++;
		strs[k] = ft_substr(s, 0, i);
		if (!strs[k])
		{
			free_k(strs);
			strs = NULL;
			return ;
		}
		s += i;
		k++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		wordcount;

	if (!s)
		return (NULL);
	wordcount = count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!strs)
		return (NULL);
	strs[wordcount] = 0;
	write_split(strs, s, c, wordcount);
	return (strs);
}
