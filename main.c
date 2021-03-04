#include "lib.h"

#define STR "hello world!"
#define STR2 "hello world!", "hello friend :)"

int list_size(t_list *head)
{
	int i = 0;
	goto campare;
incremant:
	i++;
	head = head->next;
campare:
	if (head)
		goto incremant;
	return (i);
}


void list_push_front(t_list **begin_list, void *data)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	new->data = data;
	new->next = *begin_list;
	*begin_list = new;
}

void print_list(t_list *head)
{
	while (head)
	{
		printf("%s\n", (char *)head->data);
		head = head->next;
	}
}

int main(int argc, char const *argv[])
{

	t_list *head;
	head = NULL;

	// list_push_front(&head, (void *)strdup(":("));
	// list_push_front(&head, (void *)strdup(":)"));
	// list_push_front(&head, (void *)strdup("world"));
	// list_push_front(&head, (void *)strdup("hello"));
	ft_list_push_front(&head, (void *)ft_strdup(";|"));
	ft_list_push_front(&head, (void *)ft_strdup(":("));
	ft_list_push_front(&head, (void *)ft_strdup(":)"));
	ft_list_push_front(&head, (void *)ft_strdup("world"));
	ft_list_push_front(&head, (void *)ft_strdup("hello"));

	printf("list size %d\n", ft_list_size(head));
	print_list(head);

	return 0;
}