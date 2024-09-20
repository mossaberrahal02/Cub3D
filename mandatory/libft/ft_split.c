/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:12:55 by merrahal          #+#    #+#             */
/*   Updated: 2024/03/02 16:02:01 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char *str, char sep)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == sep && *str)
			str++;
		if (*str != sep && *str)
			count++;
		while (*str != sep && *str)
			str++;
	}
	return (count);
}

static int	is_allocation_safe(char **allocatedArray, int position,
		int word_len)
{
	int	i;

	i = 0;
	allocatedArray[position] = (char *)malloc(sizeof(char) * word_len);
	if (!allocatedArray[position])
	{
		while (i < position)
			free(allocatedArray[i++]);
		free(allocatedArray);
		return (0);
	}
	return (1);
}

static int	ft_fill(char **allocatedArray, char const *givenString,
		char separator)
{
	int	word_len;
	int	i;
	int	j;

	i = 0;
	while (*givenString)
	{
		j = 0;
		word_len = 0;
		while (*givenString && *givenString == separator)
			givenString++;
		while (givenString[j] && givenString[j++] != separator)
			word_len++;
		if (word_len)
		{
			if (!is_allocation_safe(allocatedArray, i, word_len + 1))
				return (0);
			ft_strlcpy(allocatedArray[i], givenString, word_len + 1);
		}
		while (*givenString && *givenString != separator)
			givenString++;
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	int		words;

	if (!s)
		return (NULL);
	words = ft_countwords((char *)s, c);
	splited = (char **)malloc((words + 1) * sizeof(char *));
	if (!splited)
		return (NULL);
	splited[words] = NULL;
	if (!ft_fill(splited, s, c))
		return (NULL);
	return (splited);
}
