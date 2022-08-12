/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:06:58 by alprival          #+#    #+#             */
/*   Updated: 2022/04/12 21:07:56 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compteurligne(char const *s, char c)
{
	int	i;
	int	nbligne;

	nbligne = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			nbligne++;
		i++;
	}
	return (nbligne);
}

static int	ft_compteurcolone(int index, char const *s, char c)
{
	int	size;

	size = 0;
	while (s[index] != c && s[index])
	{
		size++;
		index++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		index;
	int		ligne;

	index = 0;
	ligne = -1;
	if (!s)
		return (0);
	tab = malloc(sizeof(char *) * (compteurligne(s, c) + 1));
	if (!tab)
		return (tab = ft_calloc(sizeof(char), 1));
	while (++ligne < compteurligne(s, c))
	{
		while (s[index] == c)
			index++;
		if (s[index] != c)
		{
			tab[ligne] = ft_substr(s, index, ft_compteurcolone(index, s, c));
			tab[ligne][ft_compteurcolone(index, s, c)] = 0;
		}
		index += ft_compteurcolone(index, s, c);
	}
	tab[ligne] = NULL;
	return (tab);
}
