/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:48:51 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/04 07:01:07 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

void	indxed_stack(t_stack *a)
{
	int	*list;
	int	i;
	int	n;

	n = get_size(a);
	list = bubble_sort(a, n, 0, 0);
	while (a)
	{
		i = 0;
		while (i < n)
		{
			if (a->content == list[i])
				a->index = i;
			i++;
		}
		a = a->prev;
	}
	free(list);
}

int	*bubble_sort(t_stack *orig, int n, int i, int swap)
{
	int	*list;
	int	j;

	list = (int *)malloc(sizeof(int) * n);
	while (orig)
	{
		list[swap++] = orig->content;
		orig = orig->prev;
	}
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (list[j] > list[j + 1])
			{
				swap = list[j];
				list[j] = list[j + 1];
				list[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
	return (list);
}

int	get_size(t_stack *head)
{
	int	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->prev;
	}
	return (size);
}
