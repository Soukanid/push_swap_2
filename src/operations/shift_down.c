/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:00:28 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/07 16:43:39 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../push_swap.h"
// tab must be handled
void	rrot_s(t_stack **a)
{
	t_stack	**tmp;
	t_stack *poped;

	if (!*a || !(*a)->prev)
		return ;
	tmp = (t_stack **)malloc(sizeof(t_stack *));
	*tmp = NULL;
	while ((*a)->prev)
	{
		push(tmp, pop(a)); //have been changed
		
	}
	poped = pop(a); //have been changed
	// tmp_content = (*a)->content; //have been changed
	// tmp_index = (*a)->index;
	
	while (*tmp)
		push(a, pop(tmp)); //have been changed
	push(a, poped);
	free(tmp);
}

void	rra(t_stack **a)
{
	if (!*a)
		return ;
	rrot_s(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if (!*b)
		return ;
	rrot_s(b);
	write(1, "rrb\n", 4);
}
