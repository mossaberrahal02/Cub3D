/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merrahal <merrahal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:41:37 by merrahal          #+#    #+#             */
/*   Updated: 2024/09/27 09:46:12 by merrahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_malloc
{
	void			*address_to_save;
	struct s_malloc	*next;
	bool			is_freed;
}					t_malloc;

void				gc_push(void *address_to_save);
void				_free(void);
#endif