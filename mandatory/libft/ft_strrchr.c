/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:25:36 by merrahal          #+#    #+#             */
/*   Updated: 2024/03/02 16:02:44 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	last;
	int	first;
	int	i;

	first = 0;
	i = 0;
	last = ft_strlen(s);
	if (*s == '\0' && (char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	if (*s == '\0')
		return (NULL);
	if ((char)c != '\0')
	{
		while (i <= last)
		{
			if (s[last - i] == (char)c)
				return ((char *)&s[last - i]);
			i++;
		}
	}
	else
		return ((char *)&s[ft_strlen(s)]);
	return (NULL);
}
