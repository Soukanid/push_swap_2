/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:35:00 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/07 16:49:27 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

static int	convert(char *nptr, int *i, long *res, int sign);

int	ft_atoi(char *nptr, long *num)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	sign = 1;
	while (nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	res = 0;
	i = convert(nptr, &i, &res, sign);
	*num = res * sign;
	if (((nptr[i - 1] == '-' || nptr[i - 1] == '+') && res == 0)
		|| (nptr[i] && nptr[i] != ' '))
		return (0);
	return (i);
}

static int	convert(char *nptr, int *i, long *res, int sign)
{
	while (nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		*res = *res * 10 + nptr[*i] - 48;
		(*i)++;
		if (*res * sign > 2147483647 || *res * sign < -2147483648)
			return (0);
	}
	return (*i);
}
