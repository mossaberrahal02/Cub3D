/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 02:57:49 by merrahal          #+#    #+#             */
/*   Updated: 2024/09/28 12:32:02 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void check_result(long result, int sign)
{
	if(sign == -1)
		return (ft_putstr_fd(RED"Error : negativ nbr\n"ENDC, 2), _free(), exit(1));
	if(result > 255)
		return (ft_putstr_fd(RED"Error : more then 255\n"ENDC, 2), _free(), exit(1));
}

int	ft_atoi(char *str)
{
	unsigned long	i;
	int	sign;
	unsigned long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	printf("str = {%s}\n", str);	
	while (!ft_isalpha(str, str[i]) && str[i] <= '9' && str[i] >= '0')
	{
		printf("c = (%c)\n", str[i]);
		result = result * 10 + str[i] - '0';
		check_result(result, sign);
		i++;
	}
	return (result * sign);
}
