/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:11:58 by merrahal          #+#    #+#             */
/*   Updated: 2024/03/02 16:02:33 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*allocated;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	allocated = (char *)malloc(sizeof(char) * (len + 1));
	if (!allocated)
		return (NULL);
	while (s[i])
	{
		allocated[i] = f(i, s[i]);
		i++;
	}
	allocated[i] = '\0';
	return (allocated);
}
