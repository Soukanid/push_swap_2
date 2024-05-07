/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:02:28 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/06 14:12:17 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	phase1(t_stack **a, t_stack **b, int size);
static void	phase2(t_stack **a, t_stack **b, int size);
static int	ft_sqrt(int x);

void	sort_big_num(t_stack **a, t_stack **b, int size)
{
	if (size > 5)
	{
		phase1(a, b, size);
		phase2(a, b, size);
	}
}

static void	phase1(t_stack **a, t_stack **b, int size)
{
	int	range;
	int	offset;

	offset = 0;
	range = 3 * ft_sqrt(size) / 2 - 1;
	while (*a)
	{
		while (1)
		{
			//you should minimise it
			if ((*a)->index >= offset && (*a)->index < offset + range)
			{
				pb(a, b);
				break ;
			}
			else if ((*a)->index < offset)
			{
				pb(a, b);
				rb(b);
				break ;
			}
			else
				ra(a);
		}
		offset += 1;
	}
}

static void	phase2(t_stack **a, t_stack **b, int size)
{
	t_stack	*head;
	int		last_index;
	int		post;

	last_index = size - 1;
	while (*b)
	{
		post = 0;
		head = *b;
		while (!(last_index == head->index))
		{
			head = head->prev;
			post++;
		}
		if (post > (size / 2))
			while (last_index != (*b)->index)
				rrb(b);
		else
			while (last_index != (*b)->index)
				rb(b);
		pa(a, b);
		last_index--;
		size--;
	}
}

static int	ft_sqrt(int x)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	if (x == 0 || x == 1)
		return (x);
	while (result <= x)
	{
		i++;
		result = i * i;
	}
	return (i - 1);
}
