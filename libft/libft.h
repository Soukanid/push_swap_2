/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snidbell <snidbell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:35:03 by snidbell          #+#    #+#             */
/*   Updated: 2024/05/06 09:09:19 by snidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>

int		ft_isdigit(char *str);
size_t	ft_strlen(const char *s);
int		ft_atoi(char *nptr, long *num);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
void	ft_free(char **split, int len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif