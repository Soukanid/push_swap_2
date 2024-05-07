/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_from_to.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:07:10 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/07 16:23:07 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../push_swap.h"

//have been changed
void	push_from_to(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	push(b,pop(a)); //here
}

void	pa(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	push_from_to(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	push_from_to(a, b);
	write(1, "pb\n", 3);
}
