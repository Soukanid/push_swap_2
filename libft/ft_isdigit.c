/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:34:57 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/04 06:48:09 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			return (1);
		i++;
	}
	return (0);
}
