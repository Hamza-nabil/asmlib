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

char *C_strdup(const char *s)
{
	int len = ft_strlen(s) + 1;
	char *str = malloc(len);
	str = ft_strcpy(str,s);
	return str;
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

	char *s = strdup(STR);
	// char *s = ft_strdup(STR);

	// printf("str =\t%s\n", STR);
	// int fd = open("file_test", O_CREAT | O_WRONLY | O_RDONLY, 0666);
	// printf("strcmp =\t%d\n", strcmp(STR2));
	// printf("ft_strcmp =\t%d\n", ft_strcmp(STR2));

	// printf("strlen =\t%lu\n", strlen(STR));
	// printf("ft_strlen =\t%lu\n", ft_strlen(STR));
	strcpy(s, "koko");
	printf("strcpy =\t%s\n", s + 6);
	// printf("strcpy =\t%s\n", C_strcpy(s, "koko"));

	// ft_write(fd, STR, 13);
	// // write(0, STR, 13);
	// close(fd);
	// t_list *head;
	// head = NULL;

	// list_push_front(&head, (void *)strdup(":("));
	// list_push_front(&head, (void *)strdup(":)"));
	// list_push_front(&head, (void *)strdup("world"));
	// list_push_front(&head, (void *)strdup("hello"));
	// // ft_list_push_front(&head, (void *)strdup(":)"));
	// // ft_list_push_front(&head, (void *)strdup("world"));
	// // ft_list_push_front(&head, (void *)strdup("hello"));

	// printf("list size %d\n", ft_list_size(head));
	// print_list(head);

	return 0;
}