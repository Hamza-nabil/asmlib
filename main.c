/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao  <isel-jao@student.42.f>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:55:05 by isel-jao          #+#    #+#             */
/*   Updated: 2021/03/04 22:47:21 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

#define STR "hello world!"

// void	list_remove_if(t_list **head, void *data, int (*cmp)(),void (*free_fct)(void*))
void list_remove_if(t_list **head, void *data, int (*cmp)())
{
	printf("remove data  %s\n", (char *)data);
	t_list *tmp = *head;
	while (*head && !cmp((*head)->data, data))
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->data);
		free(tmp);
	}
	t_list *tmp2 = *head;
	while (*head && (*head)->next)
	{
		if (!cmp((*head)->next->data, data))
		{
			tmp = (*head)->next;
			(*head)->next = (*head)->next->next;
			free(tmp->data);
			free(tmp);
		}
			else
				*head = (*head)->next;
	}
	*head = tmp2;
}

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

#define STR2 "hello", "hello"

int main(int argc, char const *argv[])
{

	t_list *head;
	head = NULL;
	// printf("strcmp \t\t%d\n", strcmp(STR2));
	// printf("ft_strcmp \t%d\n", ft_strcmp(STR2));

	ft_list_push_front(&head, (void *)ft_strdup(";|"));
	ft_list_push_front(&head, (void *)ft_strdup(":("));
	ft_list_push_front(&head, (void *)ft_strdup(":)"));
	ft_list_push_front(&head, (void *)ft_strdup("world"));
	ft_list_push_front(&head, (void *)ft_strdup("hello"));
	printf("list size %d\n", ft_list_size(head));
	print_list(head);
	// list_remove_if(&head, (void *)("hello"));
	list_remove_if(&head, (void *)(";|"), &strcmp);
	printf("list size %d\n", ft_list_size(head));
	print_list(head);

	return 0;
}