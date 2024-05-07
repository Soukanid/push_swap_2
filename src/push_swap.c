/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:35:22 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/07 16:38:16 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;

	if (argc == 1)
		return (0);
	a = (t_stack **)malloc(sizeof(t_stack *));
	*a = NULL;
	parser(argv, a, 1);
	a = up_down_stack(a);
	if (!is_sorted(*a))
	{
		free_stack(a);
		return (0);
	}
	b = (t_stack **)malloc(sizeof(t_stack *));
	*b = NULL;
	indxed_stack(*a);
	sort_small(a, b, get_size(*a));
	sort_big_num(a, b, get_size(*a));
	free_stack(a);
	free_stack(b);
}
