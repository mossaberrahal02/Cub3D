/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:54:06 by merrahal          #+#    #+#             */
/*   Updated: 2024/09/28 12:33:19 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(char *str, int c)
{
	if((str[0] == '+' || str[0] == '-') && str[1] == '\0')
	{
		printf("bad character in c or f\n");
		_free();
		exit(1);
	}
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A') || c == '+' || c == '-')
	{
		printf("bad character in c or f\n");
		_free();
		exit(1);
		return (1);
	}
	else
		return (0);
}
