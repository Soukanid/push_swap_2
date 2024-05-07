/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manupl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:18:21 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/07 16:30:03 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//this part need some serios work ??

//been modified 

// void	push(t_stack **head, int content, int index)
// {
// 	t_stack	*new;

// 	new = malloc(sizeof (t_stack));
// 	new->content = content;
// 	new->index = index;
// 	if (*head == NULL)
// 	{
// 		new->prev = NULL;
// 		*head = new;
// 	}
// 	else if (*head)
// 	{
// 		(*head)->next = new;
// 		new->prev = *head;
// 		*head = new;
// 	}
// 	new->next = NULL;
// }


void push(t_stack **head, t_stack *new)
{
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}
	else if (*head)
	{
		(*head)->next = new;
		new->prev = *head;
		*head = new;
	}
	new->next = NULL;	
}
//been modified
// let's do ut
t_stack	*pop(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*node;

	if (!*head)
		return (NULL);
	if (!((*head)->prev))
	{
		node = *head;
		*head = NULL;
		return (node);
	}
	tmp = (*head)->prev;
	tmp->next = NULL;
	node = *head;
	*head = tmp;
	return (node);
}

void	free_stack(t_stack **head)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = (*head)->prev;
		free(*head);
		*head = tmp;
	}
	free(head);
}

//been modified
t_stack	**up_down_stack(t_stack **head)
{
	t_stack	**tmp;
	t_stack	*node_tmp;
	t_stack *poped_node;

	tmp = (t_stack **)malloc(sizeof(t_stack *));
	*tmp = NULL;
	while (*head)
	{
		node_tmp = (*head)->prev;
		poped_node = pop(head);
		push(tmp, poped_node);
		*head = node_tmp;
	}
	free(head);
	head = tmp;
	return (head);
}
