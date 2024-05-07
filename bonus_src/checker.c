/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 07:16:43 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/06 14:12:43 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;

	if (argc == 1)
		return (1);
	a = (t_stack **)malloc(sizeof(t_stack *));
	*a = NULL;
	parser(argv, a, 1);
	a = up_down_stack(a);
	b = (t_stack **)malloc(sizeof(t_stack *));
	*b = NULL;
	read_line(a, b);
	free_stack(a);
	free_stack(b);
}

void	read_line(t_stack **a, t_stack **b)
{
	char	*buffer;
	char	**ope;

	buffer = get_next_line(0);
	while (buffer)
	{
		ope = ft_split(buffer, '\n'); //you can as well without it 
		if (!ft_strchr(buffer, '\n') || !*ope
			|| operate(ope[0], a, b))
		{
			free(buffer);
			ft_free(ope, 1);
			free_stack(b);
			throw_error("Error\n", a);
		}
		free(buffer);
		ft_free(ope, 1);
		buffer = get_next_line(0);
	}
	if (!is_sorted(*a) && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	operate(char *ope, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(ope, "pa"))
		push_from_to(b, a);
	else if (!ft_strcmp(ope, "pb"))
		push_from_to(a, b);
	else if (!ft_strcmp(ope, "sa"))
		swap_s(a);
	else if (!ft_strcmp(ope, "sb"))
		swap_s(b);
	else if (!ft_strcmp(ope, "ss"))
	{
		swap_s(a);
		swap_s(b);
	}
	else if (!ft_strcmp(ope, "rra"))
		rrot_s(a);
	else if (!ft_strcmp(ope, "rrb"))
		rrot_s(b);
	else if (!ft_strcmp(ope, "ra") || !ft_strcmp(ope, "rb")
		|| !ft_strcmp(ope, "rr") || !ft_strcmp(ope, "rrr"))
		extra(ope, a, b);
	else
		return (1);
	return (0);
}

void	extra(char *ope, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(ope, "rrr"))
	{
		rrot_s(a);
		rrot_s(b);
	}
	else if (!ft_strcmp(ope, "ra"))
		rot_s(a);
	else if (!ft_strcmp(ope, "rb"))
		rot_s(b);
	else if (!ft_strcmp(ope, "rr"))
	{
		rot_s(a);
		rot_s(b);
	}
}
