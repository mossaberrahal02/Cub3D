/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:39:13 by merrahal          #+#    #+#             */
/*   Updated: 2024/09/21 18:25:09 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	tab = (void *)malloc(size * count);
	if (!tab)
		return (NULL);
	if (size == 0 || count == 0)
		ft_bzero(tab, 1);
	ft_bzero(tab, size * count);
	return ((void *)tab);
}
