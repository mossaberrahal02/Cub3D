/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:58:13 by merrahal          #+#    #+#             */
/*   Updated: 2024/03/02 16:02:40 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*tofind == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		while (str[i + j] == tofind[j] && str[i + j] && i + j < len)
			j++;
		if (!tofind[j])
			return ((char *)(str + i));
		j = 0;
		i++;
	}
	return (0); // <---- type caste to char * ??
}
