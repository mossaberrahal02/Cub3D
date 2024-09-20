/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:08:00 by merrahal          #+#    #+#             */
/*   Updated: 2024/03/02 16:01:10 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_fill(char *allocated, int len, int nbr)
{
	while (nbr != 0)
	{
		allocated[len--] = nbr % 10 + 48;
		nbr /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		len_of_number;
	char	*allocated;

	len_of_number = ft_nbr_len(n);
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	allocated = (char *)malloc(sizeof(char) * (len_of_number + 1));
	if (!allocated)
		return (NULL);
	allocated[len_of_number--] = '\0';
	if (n < 0)
	{
		allocated[0] = '-';
		n *= -1;
		ft_fill(allocated, len_of_number, n);
	}
	else
		ft_fill(allocated, len_of_number, n);
	return (allocated);
}
