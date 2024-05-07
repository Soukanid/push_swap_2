/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:30:15 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/07 16:20:16 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				index;
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//----------------------------parsing----------------------------
//---------------------------------------------------------------

void	throw_error(char *str, t_stack **a);
void	parser(char **argv, t_stack **head, int i);
void	check_dupl(t_stack **head, int num);
int		spaces(char *str);
int		is_sorted(t_stack *a);

//-----------------------------sorting---------------------------
//----------------------------------------------------------------

void	indxed_stack(t_stack *a);
int		get_size(t_stack *head);
int		*bubble_sort(t_stack *orig, int n, int i, int swap);
void	sort_small(t_stack **a, t_stack **b, int size);
void	sort_big_num(t_stack **a, t_stack **b, int size);

// ----------------------------stack manupilation-----------------
//----------------------------------------------------------------

// void	push(t_stack **head, int content, int index); have been changed
void push(t_stack **head, t_stack *new); //have been changed
t_stack	*pop(t_stack **head); //heve been changed
void	free_stack(t_stack **head);
t_stack	**up_down_stack(t_stack **head); //have been changed

//---------------------------operations------------------------
//-------------------------------------------------------------

void	sa(t_stack **a);
void	sb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

//--------------------------bonus---------------------------------
//----------------------------------------------------------------

void	push_from_to(t_stack **a, t_stack **b);
void	swap_s(t_stack **a);
void	rrot_s(t_stack **a);
void	rot_s(t_stack **a);
void	read_line(t_stack **a, t_stack **b);
int		operate(char *ope, t_stack **a, t_stack **b);
void	extra(char *ope, t_stack **a, t_stack **b);

#endif
