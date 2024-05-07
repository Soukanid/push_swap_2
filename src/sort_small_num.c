/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:48:34 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/04 07:03:29 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three_two(t_stack **a, int size);

void	sort_small(t_stack **a, t_stack **b, int size)
{
	sort_three_two(a, size);
	if (size == 4)
	{
		while ((*a)->index != 0)
			rra(a);
		pb(a, b);
		sort_small(a, b, 3);
		pa(a, b);
	}
	else if (size == 5)
	{
		while (size--)
		{
			if ((*a)->index == 0 || (*a)->index == 1)
				pb(a, b);
			else if (get_size(*b) != 2)
				ra(a);
		}
		if (!is_sorted(*b))
			sb(b);
		sort_small(a, b, 3);
		pa(a, b);
		pa(a, b);
	}
}

static void	sort_three_two(t_stack **a, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3 && is_sorted(*a))
	{
		if ((*a)->content < (*a)->prev->prev->content
			|| ((*a)->content > (*a)->prev->content
				&& (*a)->prev->content > (*a)->prev->prev->content))
			sa(a);
		if ((*a)->content > (*a)->prev->content
			&& is_sorted(*a))
			ra(a);
		else if ((*a)->prev->content > (*a)->prev->prev->content
			&& is_sorted(*a))
			rra(a);
	}
}
