/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:51:43 by alprival          #+#    #+#             */
/*   Updated: 2022/04/14 13:55:32 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_check(char s1, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	int		i;
	int		x;
	int		j;

	if (!s1 || !set)
		return (0);
	i = 0;
	x = 0;
	j = ft_strlen(s1);
	while (ft_check(s1[i], (char *)set) == 1)
		i++;
	while (ft_check(s1[j - 1], (char *)set) == 1)
		j--;
	if (j == 0 && (size_t)i == ft_strlen(s1))
		tab = ft_calloc(sizeof(char), 1);
	else
		tab = malloc(sizeof(char) * (j - i) + 1);
	if (!tab)
		return (0);
	while (i < j)
		tab[x++] = s1[i++];
	tab[x] = '\0';
	return (tab);
}
