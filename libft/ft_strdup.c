/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:34:31 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/04 06:48:57 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*rst;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	rst = (char *)malloc ((len +1) * sizeof(char));
	if (!rst)
		return (NULL);
	while (s[i])
	{
		rst[i] = s[i];
		i++;
	}
	rst[i] = '\0';
	return (rst);
}
