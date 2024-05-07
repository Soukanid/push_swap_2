/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:14:45 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/05 17:02:31 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstclear(t_line **lst)
{
	t_line	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->str);
		free(*lst);
		(*lst) = tmp;
	}
	*lst = NULL;
}

char	*new_to_lst(t_line **lst, char **st)
{
	t_line	*tmp;
	t_line	*new;

	new = (t_line *)malloc(sizeof(t_line));
	if (!new)
		return (free(*st), ft_lstclear(lst), NULL);
	new->str = (char *)malloc ((ft_strlen1(*st) + 1));
	if (!(new->str))
		return (free (*st), ft_lstclear(lst), NULL);
	fill(new->str, *st, ft_strlen1(*st));
	free(*st);
	new->next = NULL;
	if (!(*lst))
	{
		*lst = new;
		return ("done");
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return ("done");
}

char	*ft_lst_groupstr(t_line *lst)
{
	char	*rst;
	int		i;
	int		j;
	t_line	*tmp;

	i = 0;
	tmp = lst;
	while (tmp && tmp->str)
	{
		i += ft_strlen1(tmp->str);
		tmp = tmp->next;
	}
	rst = (char *)malloc(sizeof(char) * (i + 1));
	if (!rst)
		return (ft_lstclear(&lst), NULL);
	i = 0;
	while (lst && lst->str)
	{
		j = 0;
		while ((lst->str)[j])
			rst[i++] = (lst->str)[j++];
		lst = lst->next;
	}
	rst[i] = '\0';
	return (rst);
}

size_t	ft_strlen1(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}
