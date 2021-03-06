/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-jao  <isel-jao@student.42.f>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:55:05 by isel-jao          #+#    #+#             */
/*   Updated: 2021/03/06 13:11:20 by isel-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

#define STR "hello world!"

void ft_list_remove_if(t_list **head, void *data, int (*cmp)());


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



void list_remove_if(t_list **head, void *data, int (*cmp)())
{
	t_list *tmp = *head;
	while (*head )
	{
		if (cmp((*head)->data, data) != 0)
			break;
		tmp = *head;
		*head = (*head)->next;
		free(tmp->data);
		free(tmp);
	}
	if (!(*head))
		return;
	t_list *tmp2 = *head;
	while ((*head)->next)
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
void print_list(t_list *head)
{
	while (head)
	{
		printf("%s\n", (char *)head->data);
		head = head->next;
	}
}

#define STR2 "hello", "hello"

int			atoi_base(char *str, int base)
{
	int result;
	int signe;
	int n;

	result = 0;
	signe = 1;
	if (base < 2 || base > 16)
		resulturn (0);
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\r' || *str == '\f')
			str++;
	if (base == 10 && *str == '-')
	{
		signe = -1;
		str++;
	}
	while(*str)
	{
		if (*str >= 97)
			n = *str - 87;
		else if (*str >= 65)
			n = *str - 55;
		else
			n = *str - 48;
		if (n < 0 || n >= base)
			break;
		result = result * base + n;
		str++;
	}
	return (result * signe);
}

int main(int argc, char const *argv[])
{

	// t_list *head;
	// head = NULL;
	// ft_list_push_front(&head, ft_strdup("000"));
	// ft_list_push_front(&head, ft_strdup("008"));
	// ft_list_push_front(&head, ft_strdup("008"));
	// ft_list_push_front(&head, ft_strdup("007"));
	// ft_list_push_front(&head, ft_strdup("006"));
	// ft_list_push_front(&head, ft_strdup("005"));
	// ft_list_push_front(&head, ft_strdup("005"));
	// ft_list_push_front(&head, ft_strdup("004"));
	// ft_list_push_front(&head, ft_strdup("003"));
	// ft_list_push_front(&head, ft_strdup("002"));
	// ft_list_push_front(&head, ft_strdup("001"));
	// ft_list_push_front(&head, ft_strdup("001"));
	// ft_list_push_front(&head, ft_strdup("002"));
	// ft_list_push_front(&head, ft_strdup("000"));
	// ft_list_push_front(&head, ft_strdup("000"));
	// ft_list_push_front(&head, ft_strdup("000"));
	// ft_list_push_front(&head, ft_strdup("000"));
	// ft_list_push_front(&head, ft_strdup("000"));
	// ft_list_push_front(&head, ft_strdup("000"));
	// ft_list_push_front(&head, ft_strdup("000"));
	// ft_list_push_front(&head, ft_strdup("000"));
	// ft_list_push_front(&head, ft_strdup("000"));
	// ft_list_push_front(&head, ft_strdup("000"));
	// printf("list size %d\n", ft_list_size(head));
	// print_list(head);
	// ft_list_remove_if(&head, ("008"), &strcmp);
	// printf("list size %d\n", ft_list_size(head));
	// print_list(head);

	printf("%d\n", atoi_base("-fe", 16));
	return 0;
}