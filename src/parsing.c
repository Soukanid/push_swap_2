/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:35:19 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/07 16:47:47 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

//have been changed 
void	parser(char **argv, t_stack **head, int i)
{
	int		j;
	int		c;
	long	num;
	t_stack	*new;

	while (argv[i])
	{
		if (!spaces(argv[i]))
			throw_error("Error\n", head);
		j = 0;
		while (argv[i][j])
		{
			c = ft_atoi(argv[i] + j, &num);
			j += c;
			if (c == 0)
				throw_error("Error\n", head);
			if (argv[i][j - 1] != ' ')
			{
				check_dupl(head, num);
				new = (t_stack *)malloc(sizeof(t_stack));
				new->content = num; //here ther is a changing /
				new->index = -1;
				push(head, new);
			}
		}
		i++;
	}
}

void	check_dupl(t_stack **head, int num)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->content == num)
			throw_error("Error\n", head);
		tmp = tmp->prev;
	}
}

int	spaces(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	if (!a)
		return (0);
	a = a->prev;
	while (a)
	{
		if (a->content < a->next->content)
			return (1);
		a = a->prev;
	}
	return (0);
}

void	throw_error(char *str, t_stack **a)
{
	if (str)
		write(2, str, ft_strlen(str));
	free_stack(a);
	exit(1);
}
