/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:17:12 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/07 16:27:46 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../push_swap.h"

void	rot_s(t_stack **a)
{
	t_stack	**tmp;
	// int		tmp_content;
	// int		tmp_index;
	t_stack	*poped;

	if (!*a || !(*a)->prev)
		return ;
	tmp = (t_stack **)malloc(sizeof(t_stack *));
	*tmp = NULL;
	poped = pop(a); //have been changed
	// tmp_content = (*a)->content;
	// tmp_index = (*a)->index;
	while ((*a))
	{
		push(tmp, pop(a)); //have been changed
	}
	push(a, poped);
	while (*tmp)
		push(a,pop(tmp)); //have been changed
	free(tmp);
}

void	ra(t_stack **a)
{
	if (!*a)
		return ;
	rot_s(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if (!*b)
		return ;
	rot_s(b);
	write(1, "rb\n", 3);
}
