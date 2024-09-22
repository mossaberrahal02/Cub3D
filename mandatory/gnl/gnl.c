/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:21:14 by merrahal          #+#    #+#             */
/*   Updated: 2024/09/22 08:28:18 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*get_after_nl(char *str)
{
	size_t	i;
	char	*tmp;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] != '\0')
		i++;
	else
		return (NULL);
	tmp = ft_strdup(str + i);
	gc_push(tmp);
	return (tmp);
}

char	*get_before_nl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	return (ft_substr(str, 0, i + 1));
}

char	*ft_free(char **result)
{
	*result = NULL;
	return (NULL);
}

char	*get_line2(int fd, char **result)
{
	char	*str;
	int		there_is_nl;
	int		read_return ;

	there_is_nl = ft_strchr2(*result, '\n');
	str = malloc(BUFFER_SIZE + 1);
	gc_push(str);
	while (!there_is_nl)
	{
		read_return = read(fd, str, BUFFER_SIZE);
		if (read_return < 0)
			return (ft_free(result));
		str[read_return] = '\0';
		*result = ft_strjoin(*result, str);
		gc_push(*result);
		if (read_return == 0 && *result[0] != '\0')
			return (*result);
		there_is_nl = ft_strchr2(*result, '\n');
		if (read_return == 0)
			return (ft_free(result));
	}
	return (*result);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	str = get_line2(fd, &str);
	line = get_before_nl(str);
	str = get_after_nl(str);
	return (line);
}
