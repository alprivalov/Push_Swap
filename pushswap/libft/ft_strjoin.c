/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:10:36 by alprival          #+#    #+#             */
/*   Updated: 2022/04/14 13:58:38 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		j;
	int		len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	j = 0;
	tab = malloc(sizeof(char) * len + 2);
	if (!tab)
		return (NULL);
	while (s1[++i])
		tab[i] = s1[i];
	j = i - 1;
	i = -1;
	while (s2[++i])
	{
		tab[++j] = s2[i];
	}
	tab[j + 2] = 0;
	tab[j + 1] = ' ';
	return (tab);
}
