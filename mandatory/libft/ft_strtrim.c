/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:18:11 by merrahal          #+#    #+#             */
/*   Updated: 2024/03/02 16:02:49 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s || !set)
		return (NULL);
	start = 0;
	while (ft_strchr(set, s[start]) && s[start])
		start++;
	end = ft_strlen(s);
	if (end > 0)
	{
		while (ft_strchr(set, s[end - 1]) && start < end)
			end--;
	}
	return (ft_substr(s, start, end - start));
}
