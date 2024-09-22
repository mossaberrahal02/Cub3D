#include "cub3d.h"

t_malloc	**get_head(void)
{
	static t_malloc	*head_;

	return (&head_);
}

void	add_back_to_gc(t_malloc *new)
{
	t_malloc	**head;
	t_malloc	*tmp;

	head = get_head();
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	gc_push(void *address_to_save)
{
	t_malloc	**head;
	t_malloc	*node;

	head = get_head();
	node = malloc(sizeof(t_malloc));
	if (!node)
		printf("gc failed\n");
	node->address_to_save = address_to_save;
	node->next = NULL;
	node->is_freed = false;
	if (!*head)
		*head = node;
	else
		add_back_to_gc(node);
}

void	_free(void)
{
	t_malloc	*tmp;
	t_malloc	**head;
	t_malloc	*next;

	head = get_head();
	tmp = *head;
	while (tmp)
	{
		if (tmp)
		{
			free(tmp->address_to_save);
			tmp->address_to_save = NULL;
		}
		next = tmp->next;
		if (tmp)
			free(tmp);
		tmp = next;
	}
	*head = NULL;
}
