/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:09:49 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/05 16:57:54 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	len_word;

	i = 0;
	len_word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			len_word++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (len_word);
}

void	ft_free(char **split, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**allocate(char **res, char const	*s, char c, int i)
{
	int	len_word;
	int	nbrword;

	nbrword = 0;
	while (s[i])
	{
		len_word = 1;
		if (s[i] != c)
		{
			while (s[i + len_word] && s[i + len_word] != c)
				len_word++;
			res[nbrword] = malloc((len_word + 1) * sizeof(char));
			if (!res[nbrword])
			{
				ft_free(res, nbrword);
				return (NULL);
			}
			ft_strlcpy(res[nbrword++], s + i, len_word + 1);
		}
		i += len_word;
	}
	res[nbrword] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		len_array;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	res = NULL;
	len_array = count_word(s, c);
	res = (char **)malloc(sizeof(char *) * (len_array + 1));
	if (!res)
		return (NULL);
	return (allocate(res, s, c, i));
}
