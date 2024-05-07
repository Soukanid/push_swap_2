/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:48:56 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/06 09:08:52 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../push_swap.h"

void	swap_s(t_stack **a)
{
	int	conten_swap;
	int	index_swap;

	if (!*a || !(*a)->prev)
		return ;
	conten_swap = (*a)->content;
	(*a)->content = (*a)->prev->content;
	(*a)->prev->content = conten_swap;
	index_swap = (*a)->index;
	(*a)->index = (*a)->prev->index;
	(*a)->prev->index = index_swap;
}

void	sa(t_stack **a)
{
	if (!*a)
		return ;
	swap_s(a);
	write (1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (!*b)
		return ;
	swap_s(b);
	write (1, "sb\n", 3);
}
